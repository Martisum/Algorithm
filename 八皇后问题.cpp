#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
#define maxm 1001
bool vis[3][maxm];
int e[maxm][maxm];
int cnt,n;

void dfs(int h){
	if(h>n){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){  //这可以直接使用一列表示一整行
		//第一条是表示列，第二条是表示左上右下方向，第三条是右上左下方向，直接表示一整行斜线或直线！ 
		if(vis[0][i]==0 && vis[1][n+h-i]==0 && vis[2][h+i]==0){
			e[h][i]=vis[0][i]=vis[1][n+h-i]=vis[2][h+i]=1;
			dfs(h+1);
			e[h][i]=vis[0][i]=vis[1][n+h-i]=vis[2][h+i]=0; 
		}   
	}
	return;
}

int main(){
	memset(e,0,sizeof(e));
	memset(vis,0,sizeof(e));
	std::ios::sync_with_stdio(false);
	cin>>n; 
	dfs(1);
	cout<<cnt; 
	return 0;
}

