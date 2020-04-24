#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=2019;
int e[maxm][maxm],a,b,m,n; 
bool vis[maxm][maxm];

bool on(int x,int y){
	if(x<0||y<0||x>n||y>m) return 0;
//	else if(x==a-2&&y=b-1) return 0;
//	else if(x==a-1&&y=b-2) return 0;
//	else if(x==a+2&&y=b-1) return 0;
//	else if(x==a+1&&y=b-2) return 0;
//	else if(x==a-2&&y=b+1) return 0;
//	else if(x==a-1&&y=b+2) return 0;
//	else if(x==a+2&&y=b+1) return 0;
//	else if(x==a+1&&y=b+2) return 0;
	return 1;
}

int que[3][maxm],head=1,tail=2;
void bfs(int x,int y){ 
	que[1][head]=x;
	que[2][head]=y;
	
	while(tail-head){
		for(int i=1;i<=2;i++){
			int tx=que[1][head],ty=que[2][head];
			if(i==1){ty++;}
			else{tx++;}
			
			if(on(tx,ty)&&vis[tx][ty]==0){
				que[1][tail]=tx;
				que[2][tail++]=ty;
				if(on(tx-1,ty)) e[tx][ty]+=e[tx-1][ty];
				if(on(tx,ty-1)) e[tx][ty]+=e[tx][ty-1];
				vis[tx][ty]=1;
				if(tx==n&&ty==m) return;
			}
		}
		head++;
	}
	return;
}

void init(){
	e[0][0]=1;
	vis[a][b]=1;
	vis[a-2][b-1]=vis[a-1][b-2]=1;
	vis[a+2][b-1]=vis[a+1][b-2]=1;
	vis[a-2][b+1]=vis[a-1][b+2]=1;
	vis[a+2][b+1]=vis[a+1][b+2]=1;
	return;
}

int main(){
//	freopen("gin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>a>>b;
	init();
	bfs(0,0);
//	for(int i=0;i<=6;i++){
//		for(int j=0;j<=6;j++){
//			cout<<e[i][j]<<"      ";
//		}cout<<endl;
//	}
	cout<<e[n][m]<<endl;
	return 0;
}

