#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1001;
struct graph{
	int from;
	int to;
};struct graph map[maxm];  //���ڷ�ת�ı߱� 
int p,s,e[maxm][maxm];  //�������������ڽӾ��� 
int color[maxm],begin; //dfs��¼�߹��ĵ㡢dfs��ʼ�� 
int book[maxm],cnt,result[maxm],time;  //��һ��dfs�˳��ĵ㡢��ʱ�������� CC
int fa[maxm];  //���岢�鼯 

int get(int x){  //������ 
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
	for(int i=1;i<=(cnt+1)>>1;i++) swap(book[i],book[cnt+1-i]); //����book 
	return;
}

void kosaraju(int start){  //�ڶ������� 
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
	}for(int i=1;i<=p;i++) fa[i]=i;  //��ʼ�����鼯 
	
	color[begin]=1;  //����������Ҫ���һ�� 
	dfs(begin);
	book[++cnt]=begin;  //�����˳��󲻻��¼����˳����Ǹ��㣬�ڴ��صر�� 
	for(int i=1;i<=p;i++) color[i]=0;  //��ʼ��color���鷽����һ������ 
	
	reverse(); 
	result[++time]=book[1];
	for(int i=1;i<=cnt;i++){ 
		color[book[i]]=1;
		kosaraju(book[i]);
	}
	
	for(int i=1;i<=p;i++) cout<<result[i]<<endl;
	return 0;
}
