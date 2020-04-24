#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1000001
int cnt=0,data[maxm];
char n[maxm];

int main(){
	gets(n);
	for(int i=0;i<=strlen(n)-1;i++) data[i+1]=n[i]-48;
	int r=data[++cnt];
	while(cnt<strlen(n)) r=(r<<1)+data[++cnt];
	cout<<r;
	return 0;
}
