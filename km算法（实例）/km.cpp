#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f
const long long maxm=10001;
int p,s;
struct e{
	int u,v,dis,next;
}edge[maxm];
int head[maxm],js;
int nx[maxm],ny[maxm];
int numx[maxm],numy[maxm];
int slack[maxm];
int l[maxm],lx;
bool visx[maxm],visy[maxm];
int a,b,c;
int d;

void addedge(int u,int v,int d){
	edge[++js].u=u;
	edge[js].v=v;
	edge[js].dis=d;
	edge[js].next=head[u];
	head[u]=js;
	return;
}

bool dfs(int x){
	visx[x]=1;
	for(int i=head[x];i;i=edge[i].next){
		if(numx[x]+numy[edge[i].v]==edge[i].dis){
			if(!visy[edge[i].v]){
				visy[edge[i].v]=1;
				if(!ny[edge[i].v] || dfs(ny[edge[i].v])){
					ny[edge[i].v]=x;
					nx[x]=edge[i].v;
					return 1;
				}
			}
		}
		//计算当前的最小减少点标（因为最后还要用for选出真正最小的）
		else slack[edge[i].v]=min(slack[edge[i].v],numx[x]+numy[edge[i].v]-edge[i].dis); 
	}
	return 0;
}

void km(){  //km算法核心代码
	for(int i=1;i<=lx;i++){  //初始化给予每一个点的初始点标
		for(int j=head[l[i]];j;j=edge[j].next){
			numx[l[i]]=max(numx[l[i]],edge[j].dis);
		}
	}
	
	for(int i=1;i<=lx;i++){
		while(1){
			memset(slack,inf,sizeof(slack));
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(l[i])) break;
			
			d=inf;  //inf是常量，不可以变化
			for(int j=1;j<=p;j++){
				if(!visy[p]){
					d=min(d,slack[j]);
				}
			}
			for(int j=1;j<=p;j++){
				if(visy[j]) numy[j]+=d;
				if(visx[j]) numx[j]-=d;
			}
		}
	}
	return;
}

int main(){
	freopen("kin.txt","r",stdin);
	cin>>p>>s>>lx;
	for(int i=1;i<=s;i++){
		cin>>a>>b>>c;
		addedge(a,b,c);
	}for(int i=1;i<=lx;i++) cin>>l[i];
	
	km();
	
	for(int i=1;i<=lx;i++) cout<<nx[i]<<"配"<<i<<endl;
	return 0;
}
