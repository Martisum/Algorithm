#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=1001;
int n,f[maxm][maxm],e[maxm][maxm],r[3][maxm][maxm];

int maxs(int x,int y,int a,int b){
	if(x>y){
		r[1][a][b]=a+1;
		r[2][a][b]=b;
		return x;
	}else{
		r[1][a][b]=a+1;
		r[2][a][b]=b+1;
		return y;
	}
}

int main(){
	freopen("sin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>e[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		f[n][i]=e[n][i];
	}
	
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			f[i][j]=maxs(f[i+1][j],f[i+1][j+1],i,j)+e[i][j];
		}
	}
	cout<<f[1][1]<<endl;
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			cout<<r[1][i][j]<<","<<r[2][i][j]<<" ";
//		}cout<<endl;
//	}
//	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			cout<<f[i][j]<<" ";
//		}cout<<endl;
//	}
	
	int p=1,q=1;
	cout<<e[p][q];
	for(int i=1;i<=n-1;i++){
		cout<<"-"<<e[r[1][p][q]][r[2][p][q]];
		p=r[1][p][q];q=r[2][p][q];
	}
	return 0;
}

