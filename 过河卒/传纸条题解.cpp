#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#define max(a,b) a>b?a:b
using namespace std;
int m,n;
int a[51][51];
int dp[51][51][51][51];
int main(){
	int i,j,i1,i2,j1,j2;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i1=1;i1<=m;i1++)
		for(j1=1;j1<=n;j1++)
			for(i2=1;i2<=m;i2++)
				for(j2=1;j2<=n;j2++){
					int p1=max(dp[i1-1][j1][i2-1][j2],dp[i1-1][j1][i2][j2-1]);
					int p2=max(dp[i1][j1-1][i2-1][j2],dp[i1][j1-1][i2][j2-1]);
					int p=max(p1,p2);
					if(i1==i2&&j1==j2)
						dp[i1][j1][i2][j2]=p+a[i1][j1];
					else
						dp[i1][j1][i2][j2]=p+a[i1][j1]+a[i2][j2];
				}
	printf("%d\n",dp[m][n][m][n]);
	return 0;
}

