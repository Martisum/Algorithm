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
		for(int j=1;j<=n-1;j++){
			if(data[j]>data[j+1]) swap(data[j],data[j+1]);
		}
	} 
	
	for(int i=1;i<=n;i++) cout<<data[i]<<endl;
	return 0;
}
