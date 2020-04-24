#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
int M,n,f[N],w[N],c[N];
int main(){
	freopen("bin.txt","r",stdin); 
	cin>>M>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=M;j++){
			f[j]=max(f[j],f[j-w[i]]+c[i]);
		}
	}
//	for (int i=1,w,c; i<=n; i++){	
//		cin>>w>>c;
//		for (int j=w; j<=M; j++)
//			f[j] = max(f[j],f[j-w]+c);
//	}
	cout<<"max="<<f[M]<<endl;
	return 0;
} 
