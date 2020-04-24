#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxm 1001
int n,m,a;
int e[maxm][maxm],b[maxm][maxm];

int main(){
	freopen("jin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>e[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]+e[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
}

