#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1001;
struct graph{
	int from;
	int to;
};struct graph map[maxm];  //用于翻转的边表 
int p,s,e[maxm][maxm];  //点数、边数、邻接矩阵 
int color[maxm],begin; //dfs记录走过的点、dfs开始处 
int book[maxm],cnt,result[maxm],time;  //第一次dfs退出的点、临时计数变量 CC
int fa[maxm];  //定义并查集 

int get(int x){  //求祖先 
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
} 

void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y) fa[y]=x;
	return;
}

void dfs(int start){
	for(int i=1;i<=p;i++){
		if(e[start][i]==1 && color[i]==0){
			color[i]=1; 
			dfs(i);
			book[++cnt]=i;
		}
	}
	return;
}

void reverse(){
	for(int i=1;i<=s;i++){
		e[map[i].from][map[i].to]=0;
		e[map[i].to][map[i].from]=1;
	}
	for(int i=1;i<=(cnt+1)>>1;i++) swap(book[i],book[cnt+1-i]); //逆序book 
	return;
}

void kosaraju(int start){  //第二次深搜 
	for(int i=1;i<=p;i++){
		if(e[start][i]==1 && color[i]==0){
			color[i]=1;
			result[++time]=i; 
//			merge(start,i); 
			dfs(i);
		}
	} 
	return;
}

int main(){
	int a,b;
	freopen("kin.txt","r",stdin);
	cin>>p>>s>>begin;
	for(int i=1;i<=s;i++){
		cin>>a>>b;
		map[i].from=a;
		map[i].to=b;
		e[a][b]=1;
	}for(int i=1;i<=p;i++) fa[i]=i;  //初始化并查集 
	
	color[begin]=1;  //进入深搜需要标记一下 
	dfs(begin);
	book[++cnt]=begin;  //深搜退出后不会记录最后退出的那个点，在此特地标记 
	for(int i=1;i<=p;i++) color[i]=0;  //初始化color数组方便下一轮深搜 
	
	reverse(); 
	result[++time]=book[1];
	for(int i=1;i<=cnt;i++){ 
		color[book[i]]=1;
		kosaraju(book[i]);
	}
	
	for(int i=1;i<=p;i++) cout<<result[i]<<endl;
	return 0;
}
