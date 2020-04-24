#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxm 1001
int n,a[maxm],f[maxm][maxm];

int ask(int l,int r){
	int k=log(r-l+1)/log(2);
	return max(f[l][k],f[r-(1<<k)+1][k]);
} 

void rmq(int n){
	for(int i=1;i<=n;i++)
		f[i][0]=a[i];
	
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++)
			if(i+(1<<j)-1<=n){
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	return;
}

int main(){
	freopen("qin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	rmq(n);
	cout<<ask(4,n);
	return 0;
}

