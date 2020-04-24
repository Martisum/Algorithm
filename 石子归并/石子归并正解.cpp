#include <bits/stdc++.h>
using namespace std;

const int maxn=100+5,INF=0x7fffffff;
int n;
int dp[maxn][maxn],s[maxn];

void solve(){
    for(int r=1;r<=n-1;r++)
        for(int i=1;i<=n-r+1;i++){
            int j=i+r;dp[i][j]=INF;
            for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
        }
    printf("%d\n",dp[1][n]);
}
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t; scanf("%d",&t);
        s[i]=s[i-1]+t;
    }
}
int main(){
    init();
    solve();
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
    return 0;
}
