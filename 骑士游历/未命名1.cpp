#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=101;
int e[maxm][maxm];
int a,b,c,d,n,m;
int dir[maxm][3];
bool vis[maxm][maxm];

bool on(int x,int y){
	if(x>n||y>m||x<1||y<1) return 0;
	return 1;
}

void init(){
	dir[1][1]=-2;dir[1][2]=-1;
	dir[2][1]=-1;dir[2][2]=-2;
	dir[3][1]=2;dir[3][2]=-1;
	dir[4][1]=1;dir[4][2]=-2;
	dir[5][1]=-2;dir[5][2]=1;
	dir[6][1]=-1;dir[6][2]=2;
	dir[7][1]=2;dir[7][2]=1;
	dir[8][1]=1;dir[8][2]=2;
	return;
}

bool finish(){
	for(int i=1;i<=8;i++){
		int tx=c+dir[1][i],ty=d+dir[2][i];
		if(on(tx,ty)==0||e[tx][ty]==0) return 0;
	}
	return 1;
}

int que[3][1001],head=1,tail=1;
void bfs(int x,int y){
	que[1][tail]=x;
	que[2][tail++]=y;
	vis[x][y]=1;
	
	while(tail-head){
		if(que[1][head]==c&&que[2][head]==d){
			for(int j=1;j<=8;j++){
				if(on(c+dir[1][j],d+dir[2][j])){
					e[c][d]+=e[c+dir[j][1]][d+dir[j][2]];
				}
			}
			if(finish()) return;
		}
		
		for(int i=1;i<=8;i++){
			int tx=que[1][head]+dir[i][1];
			int ty=que[2][head]+dir[i][2];
			
			if(on(tx,ty)&&vis[tx][ty]==0){
				que[1][tail]=tx;
				que[2][tail++]=ty;
				vis[tx][ty]=1;
				
				for(int j=1;j<=8;j++){
					if(on(tx+dir[1][j],ty+dir[2][j])){
						e[tx][ty]+=e[tx+dir[j][1]][ty+dir[j][2]];
					}
				}
			}
		}
		head++;
	}
	return;
}

int main(){
	freopen("qin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	memset(e,1,sizeof(e));
	init();
	cin>>n>>m>>a>>b>>c>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==a&&j==b){
				e[i][j]=1;
				continue;
			}
			e[i][j]=0;
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<e[i][j]<<" ";
//		}cout<<endl;
//	}
	bfs(a,b);
	cout<<e[c][d]-2<<endl;
	return 0;
}

