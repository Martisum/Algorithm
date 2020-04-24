#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001 
char a[maxm],b[maxm];
long n;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>n;
	for(int i=0;i<=strlen(a)-1;i++) cout<<a[i]<<" ";
	cout<<endl; 
	for(int i=0;i<=strlen(b)-1;i++) cout<<b[i]<<" ";
	cout<<endl;
	cout<<memcmp(a+strlen(a)-n,b,n);
	return 0;
}
