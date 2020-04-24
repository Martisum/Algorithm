#include<iostream>
#include<cstring>
using namespace std;
#define maxm 10001  //定义最大常量 
int vis[maxm];  //是否搜过 
struct edge{
	int u,v,next;  
}e[maxm];  
int head[maxm];  
int cx[maxm],cy[maxm];  //表示左、右被匹配的点
int nl,nr;  //左右点的总数 
int p,s,a,b,js;   
int lefts[maxm];  //存储左边的数 

void addedge(int u,int v){
	e[++js].u=u;
	e[js].v=v;
	e[js].next=head[u];
	head[u]=js; 
	return;
}

bool dfs(int u){ 
	vis[u]=1;  //标记当前点已被搜过  
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(!vis[v]){
			vis[v]=1;
			if(!cy[v] || dfs(cy[v])){
				cy[v]=u;
				cx[u]=v;
				return 1;				
			}
		}
	}
	return 0;
}

int main(){
	freopen("hin.txt","r",stdin);
	cin>>p>>s;  
	cin>>nl>>nr;  //读入左点数，右点数
	for(int i=1;i<=s;i++){  
		cin>>a>>b;  
		addedge(a,b);  //双向边存2遍 
		addedge(b,a);
	} 
	for(int i=1;i<=nl;i++) cin>>lefts[i];
	
	//执行匈牙利算法 
	int ans=0;
	for(int i=1;i<=nl;i++){
		dfs(lefts[i]);
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=p;i++){
		cout<<cx[i]<<"配"<<i<<endl;
	}
	return 0;
} 


















