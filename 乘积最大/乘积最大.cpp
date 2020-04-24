#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
char tn[maxm];
int num[maxm],n,k,hhh,t=1;

int main(){
	freopen("cin.txt","r",stdin); 
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>tn;
	for(int i=0;i<=strlen(tn)-1;i++)
		num[i+1]=tn[i]-'0';
	
	for(int i=n;i>=1;i--){
		hhh+=num[i]*t;
		t*=10;
	}cout<<hhh;
	return 0;
}
