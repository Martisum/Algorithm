#include<iostream>
#include<algorithm>
using namespace std;
const int N = 205;
int M,n,f[N];
int main(){
	cin>>M>>n;
	for (int i=1,w,c,p; i<=n; i++){	
		cin>>w>>c>>p;
		if (p==0){
			for (int j=w; j<=M; j++)
				f[j] = max(f[j],f[j-w]+c);
		}
		else {
			for (int j=M; j>=0; j--)
				for (int k=0; k<=p; k++)
					 if (j-k*w>=0) f[j]=max(f[j],f[j-k*w]+k*c);
		}
	}
	cout<<f[M]<<endl;
	return 0;
} 
