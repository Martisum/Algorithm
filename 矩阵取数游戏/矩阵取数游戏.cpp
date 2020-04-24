#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxm 101
long long n,m,d[maxm][maxm],f[maxm][maxm][maxm],ans;

int main(){
	freopen("jin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	
	
	
	for(int t=1;t<=m;t++){
		for(int len=n-1;len>=0;len--){
			int k=n-len-1;
			for(int l=1,r=1+len;r<=n;l++,r++){
				f[t][l][r]=max(f[t][l-1][r]+d[t][l-1]*(1<<k),f[t][l][r+1]+d[t][r+1]*(1<<k));
				if(l==r) f[t][l][r]+=(d[t][l]*(1<<n));
			}
		}
	}
	
	for(int t=1;t<=m;t++){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,f[t][i][i]);
		}ans+=maxx;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}cout<<endl;
//	}
	cout<<ans;
	return 0;
}
