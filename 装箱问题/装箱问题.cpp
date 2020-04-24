#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=30000;
int v,n,d[maxm];
int dp[50][30000]; 

int main(){
	freopen("zin.txt","r",stdin); 
	std::ios::sync_with_stdio(false);
	cin>>v>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
		
	for(int i=1;i<=v;i++){
		if(i>=d[1]) dp[1][i]=dp[1][i]-d[1]+i;
		else dp[1][i]=i;
	}
		
	for(int i=2;i<=n;i++){ 
		for(int j=1;j<=v;j++){
			dp[i][j]=j;
			if(j>=d[i]){
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-d[i]]);
			}else dp[i][j]=dp[i-1][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	
	cout<<dp[n][v];
	return 0;
}

