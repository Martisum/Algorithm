#include<iostream>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f
using namespace std;
const int maxm=2501;
struct e{
	int u,v,value,next;
	e(){u=v=value=next=0;return;}
}edge[maxm];
bool vis[maxm];
int js,head[maxm],dis[maxm];
int p,s;

void addedge(int u,int v,int value){
	edge[++js].u=u;
	edge[js].v=v;
	edge[js].value=value;
	edge[js].next=head[u];
	head[u]=js;
	return;
}

void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next){
		register int v=edge[i].v;
		if(!vis[v]&&dis[v]>dis[x]+edge[i].value){
			dis[v]=dis[x]+edge[i].value;
			dfs(v);
		}
	}
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	freopen("din.txt","r",stdin);
	memset(dis,inf,sizeof(dis));
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		register int a,b,c;
		cin>>a>>b>>c;
		addedge(a,b,c);
	}
	
	dis[1]=0;
	dfs(1);
	for(int i=1;i<=p;i++)
		cout<<dis[i]<<" ";
	return 0;
}





