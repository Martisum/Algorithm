#include<iostream>
using namespace std;
#define maxm 10001
int data[maxm],n,m,num;

void addnum(int x){
	data[x/32]|=1<<(x%32);
	return;
}

bool find(int x){
	return data[x/32]>>(x%32)&1;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num;
		addnum(num);
	}if(find(m)) cout<<"yes";
	else cout<<"no";
	return 0;
}
