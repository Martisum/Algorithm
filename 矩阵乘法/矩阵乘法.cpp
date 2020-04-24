#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
int a[maxm][maxm],b[maxm][maxm],c[maxm][maxm],n1,m1,n2,m2;

int main(){
//	freopen("jin.txt","r",stdin); 
	std::ios::sync_with_stdio(false);
	cin>>n1>>m1;
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=m1;j++){
			cin>>a[i][j];
		}
	}
	
	cin>>n2>>m2;
	for(int i=1;i<=n2;i++){
		for(int j=1;j<=m2;j++){
			cin>>b[i][j];
		}
	}
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=m2;j++){
			for(int k=1;k<=n2;k++){	
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=m2;j++){
			cout<<c[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
}

