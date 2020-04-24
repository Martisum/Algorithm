#include<bits/stdc++.h>
using namespace std;
const long long maxm=100000001;
int a,b,c,cnt,t;
int f[maxm];
int main(){
	cin>>a>>b;
	c=max(a,b);
	f[a]=f[b]=1;
	while(1>0){
		if(cnt==c) break;
		t++;
		if(f[t-a]==1 || f[t-b]==1){
			f[t]=1;
			cnt++;
			continue;
		}
		cnt=0;
	}cout<<t-cnt;
	return 0;
}
