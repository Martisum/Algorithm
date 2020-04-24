#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
int num[maxm],n;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	
	if(n==1||n==2){cout<<"1";return 0;}
	num[1]=1;num[2]=1;
	for(int i=3;i<=n;i++)
		num[i]=num[i-1]+num[i-2];
	
	cout<<num[n];
	return 0;
}

