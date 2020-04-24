#include<bits/stdc++.h>
using namespace std;
const int maxm=101;
int d[maxm],n;
int main(){
	cin>>n;
	d[1]=d[2]=1;
	for(int i=1;i<=n;i++){
		d[i+2]=d[i+1]+d[i];
	}cout<<d[n];
	return 0;
}
