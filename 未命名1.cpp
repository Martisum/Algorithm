#include<bits/stdc++.h>
using namespace std;
int s,r,times;
int n=14;
int main(){
	while(n>0){
		r=n%2;
		n=n/2;
		s=s+r;
		times++;
	}cout<<n;
	return 0;
}
