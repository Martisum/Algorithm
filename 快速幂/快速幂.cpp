#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,k,ans[2][3],a[3][3],t[3][3];

void fpow(long long p){
	for(;p;p>>=1){
		if(p&1){
			memset(t,0,sizeof(t));
			for(int i=1;i<=2;i++){
				for(int j=1;j<=2;j++){
					t[1][i]+=ans[1][j]*a[j][i];
				}
			}
			for(long long i=1;i<=2;i++){
				ans[1][i]=t[1][i];
			}
		}
		
		memset(t,0,sizeof(t));
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				for(int k=1;k<=2;k++){
					t[i][j]+=a[i][k]*a[k][j];
				}
			}
		}
		
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				a[i][j]=t[i][j]; 
			}
		}
	}	
	return;
}

void init(){
	ans[1][1]=1;ans[1][2]=1;
	a[1][1]=0;a[1][2]=1;
	a[2][1]=1;a[2][2]=1;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	while(cin>>k){
		init();
		fpow(k-1);
		cout<<ans[1][1]%1000000007<<endl;
	}
	return 0;
}
