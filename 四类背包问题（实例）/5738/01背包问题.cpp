#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1005;
int M,n,f[maxm];
int w[maxm],c[maxm];
int main(){
	freopen("bin.txt","r",stdin);
	cin>>M>>n;
	for(int i=1;i<=n;i++) cin>>w[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=M;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+c[i]);
		}
	}
	cout<<f[M]<<endl;
	return 0;
} 
