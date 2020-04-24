#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f
#define maxm 5001
#define maxn 501
int h[maxn],l[maxn],d[maxn];
int e[maxn][maxn];
int que[maxn],head=1,tail=1;
int m,n,a,b,c,s,t;
bool vis[maxn];
int cm;
	
int main(){
	freopen("sin1.txt","r",stdin);
	memset(l,inf,sizeof(l));
	memset(d,inf,sizeof(d));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		cm=max(cm,c);
		if(e[a][b]>c && e[a][b]!=0){
			d[b]=e[a][b]-c;
		} 
		e[a][b]=max(c,e[a][b]);
		e[b][a]=max(c,e[b][a]);
	}
	cin>>s>>t;
	
	vis[s]=1;
	for(int i=1;i<=n;i++){
		if(e[s][i]){
			vis[i]=1;
			que[tail++]=i;
			h[i]=l[i]=e[s][i];
		}
	}
	
	while(tail-head){
		for(int i=1;i<=n;i++){
			if(e[que[head]][i]){
				if(!vis[i]) que[tail++]=i;
				int th=h[que[head]],tl=l[que[head]];
				if(th<e[que[head]][i]) th=e[que[head]][i];
				if(tl>e[que[head]][i]) tl=e[que[head]][i];
				if(th-tl<d[i]){
					d[i]=th-tl;
					h[i]=th;
					l[i]=tl;
				}
			}
		}
		head++;
	}
	
	if(d[t]>cm) cout<<"IMPOSSIBLE"<<endl;
	else{
		int nmin;
		nmin=min(l[t],h[t]);
		for(int i=2;i<=nmin;i++){
			while(l[t]%i==0 && h[t]%i==0){
				l[t]/=i;h[t]/=i;
				nmin/=i;
			}
		}
		
		if(h[t]==l[t]) cout<<1<<endl;
		if(l[t]==1 && h[t]!=1) cout<<h[t]<<endl;
		if(h[t]!=1 && l[t]!=1 && h[t]!=l[t]) cout<<h[t]<<"/"<<l[t];
	}
	return 0;
}












