#include<iostream>
#include<algorithm>
using namespace std;
const int N = 35;
int V,n,T,a[15][N],w[N],c[N],f[205]; 
int main(){		
	cin>>V>>n>>T;
	for (int i=1,k; i<=n; i++){
		cin>>w[i]>>c[i]>>k;
		a[k][++a[k][0]] = i;	//k组号，a[k][0] k组个数, 一行存相同组编号
	}
	for (int k=1; k<=T; k++)	//所有组
		for (int i=V; i>=0; i--)	//背包容量
			for (int j=1; j<=a[k][0]; j++)	//每组所有物品
				if (i-w[a[k][j]]>=0) f[i]=max(f[i],f[i-w[a[k][j]]]+c[a[k][j]]);
	cout<<f[V]<<endl;
	return 0;
} 
