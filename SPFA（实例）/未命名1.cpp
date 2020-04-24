#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f
const int maxm=10001;
int p,s;
struct e{
	int u,v,dis,next;
}edge[maxm];
int head[maxm],js;
int a,b,c;
int que[maxm],begin,end;
int dis[maxm],start;
int vis[maxm];

void addedge(int u,int v,int dis){
	edge[++js].u=u;
	edge[js].v=v;
	edge[js].dis=dis;
	edge[js].next=head[u];
	head[u]=js;
	return;
}

void spfa(int x){
	begin=end=1;
	que[end++]=x;
	while(end-begin!=0){  //队列不为空执行循环 
		for(int i=head[que[begin]];i;i=edge[i].next){
			if(dis[edge[i].v]>dis[que[begin]]+edge[i].dis){
				dis[edge[i].v]=dis[que[begin]]+edge[i].dis;
				if(!vis[edge[i].v]){
					que[end++]=edge[i].v;
					vis[edge[i].v]=1;
				}
			}
		} 
		begin++;
	}
	return;
}

int main(){
	freopen("sin.txt","r",stdin);
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		cin>>a>>b>>c;
		addedge(a,b,c);
	}
	freopen("CON","r",stdin);
	memset(dis,inf,sizeof(dis));  //初始化dis数组  
	cin>>start;
	dis[start]=0;
	
	spfa(start);
	
	for(int i=1;i<=p;i++) cout<<dis[i]<<endl;
	return 0;
}
