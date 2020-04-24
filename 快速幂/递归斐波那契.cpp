#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
int num[maxm],n;

int f(int x){
	if(x==1||x==2) return 1;
	return f(x-1)+f(x-2);
}

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	cout<<f(n);
	return 0;
}
