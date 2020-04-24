#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=1001;
long long d[maxm],f[maxm],n;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i],f[i]=1;

	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			if(d[i]>d[j]){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	
	cout<<f[n];
	return 0;
}

