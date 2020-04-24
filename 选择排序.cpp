#include<bits/stdc++.h>
using namespace std;
#define mmax 10001
int n,data[mmax];
int main(){
	freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	
	//ºËĞÄ´úÂë 
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(data[j]<data[i]) swap(data[j],data[i]);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<data[i]<<endl;
	return 0;
}
