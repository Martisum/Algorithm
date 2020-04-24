#include<iostream>
using namespace std;
#define inf 0x3f3f3f
const int maxn=1001;
int e[maxn][maxn],p,s,a,b,c,start;
int dis[maxn],que[maxn],head,tail;

void spfa(int begin){
	for(int i=1;i<=p;i++) dis[i]=inf;
	dis[begin]=0;
	que[++head]=begin;tail=head+1;
	
	while(tail-head>0){
		for(int i=1;i<=p;i++){
			if(e[que[head]][i]!=0){
				if(dis[i]>dis[que[head]]+e[que[head]][i]){
					dis[i]=dis[que[head]]+e[que[head]][i];
					que[tail++]=i;
				}
			}
		}
		head++;
	}
	return;
}

int main(){
	freopen("sin.txt","r",stdin);
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		cin>>a>>b>>c;
		e[a][b]=c;
	}
	
	spfa(1);
	
	for(int i=1;i<=p;i++) cout<<dis[i]<<endl;
	return 0;
}
