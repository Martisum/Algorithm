/*
5
at
touch
cheat
choose
tact
a

23
（连成的“龙”为atoucheatactactouchoose）
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 101 
struct e{int u,v,next,value;}edge[maxm];
int head[maxm],js,n,ans;
char a[maxm][maxm],st;
int vis[maxm];

void addedge(int u,int v){
	edge[++js].u=u;
	edge[js].v=v;
	edge[js].value=strlen(a[u]);
	edge[js].next=head[u];
	head[u]=js;
	return;
}

void dfs(int x){
	vis[x]++;
	cout<<x<<" ";
	for(int k=head[x];k;k=edge[k].next){
		if(vis[edge[k].v]<2){
			int lena=strlen(a[edge[k].u]),lenb=strlen(a[edge[k].v]),lenc,da=0;
			lenc=min(lena,lenb);
			bool flag=0;
			for(int i=1;i<=lenc-1;i++){
				for(int j=i,g=0;j<=lena-1 && g<=lenb-1;g++,j++){
					if(a[edge[k].u][j]==a[edge[k].v][g]){
						da++;
						if(j==lena-1){flag=1;}
						continue;
					}
					break; 
				}
				if(flag) break;
				da=0;
			}
			
			edge[edge[k].v].value=max(edge[k].value,edge[k].value+lenb-da);
			dfs(edge[k].v);
		}
	} 
	return;
}

int main(){
	freopen("din.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	cin>>st;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=min(strlen(a[i]),strlen(a[j]))-1;k++){
				if(memcmp(a[i]+strlen(a[i])-k,a[j],k)==0){
					addedge(i,j);
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=strlen(a[i])-1;j++){
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
	
	for(int i=1;i<=8;i++){
			cout<<edge[i].u<<" to "<<edge[i].v<<" value: "<<edge[i].value<<endl;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i][0]==st){
			dfs(i);
			memset(vis,0,sizeof(vis));
		}
	}cout<<endl;
	
	
	
	for(int i=1;i<=n;i++){
		ans=max(ans,edge[i].value);
	}cout<<ans;
	return 0;
}
