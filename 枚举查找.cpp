#include<bits/stdc++.h>
using namespace std;
#define mmax 10001
int n,data[mmax],target;
int main(){
	freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	freopen("CON","r",stdin);
	cin>>target;
	//ºËĞÄ´úÂë 
	for(int i=1;i<=n;i++){
		if(data[i]==target) cout<<i<<endl;
	}
	

	return 0;
}
