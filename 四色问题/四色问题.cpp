#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=101; 
bool e[9][9];
int c[maxm],n,cnt=1,ans;

void dfs(int x,int col){
	if(cnt>=n){ans++;return;}
	
	for(int i=1;i<=n;i++){
		if(e[x][i] && c[i]==0){
			for(int j=1;j<=4;j++){
				if(j==col) continue;
				cnt++;c[i]=j;
				dfs(i,j);
				cnt--;c[i]=0;
			}
		}
	}
	return;
}

int main(){
	freopen("sin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>e[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			for(int j=1;j<=4;j++){
				c[i]=j;
				dfs(i,j);
				c[i]=0;
			}
		}
		cnt=0;
	}
	
	cout<<ans;
	return 0;
}

