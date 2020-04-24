#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f
#define maxm 5001
#define maxn 501
int e[maxm][maxm];
bool vis[maxm],flag;
int nmax=inf,nmin;
int cmax[maxn],cmin[maxn],cnt=1;  //每一次深搜中的最大和最小
int m,n,a,b,c;
int s,t;  //出发点和终点,判断有无搜到 
int timeup;  //优化深搜防止重复 

void dfs(int x){
	vis[x]=1;timeup--;
	if(x==s){
		flag=1;
		return;
	}
	for(int i=1;i<=m;i++){
		if(e[x][i] && !vis[i]){
			cmax[cnt]=max(cmax,e[x][i]);
			cmin[cnt]=min(nmin,e[x][i]);
			dfs(i);
		}
	}
	return;
}

int main(){
	freopen("sin2","r",stdin);
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=max(c,e[a][b]);
		e[b][a]=max(c,e[b][a]);
	}
	scanf("%d %d",&s,&t);
	timeup=m; 
	
	memset(cmax,0,sizeof(cmax));
	memset(cmin,inf,sizeof(cmin));
	for(int i=1;i<=n;i++){
		dfs(s);
		memset(vis,0,sizeof(vis));
		if(!timeup) break;
	}for(int i=1;i<=cnt;i++){
		nmax=min(nmax,cmax[i]);
		nmin=max(nmin,cmin[i]);
	}
	
	if(flag){
		int tmin=nmin;  //拿一个临时变量存nmin，因为nmin要约分 
		for(int i=2;i<=tmin;i++){
			while(nmax&i==0 && nmin%i==0){
				nmax/=i;nmin/=i;
				tmin/=i;
			}
		}
		printf("%d/%d",nmax,nmin);
	}else printf("IMPOSSIBLE");
	return 0;
}
