#include<iostream>
using namespace std;
int *p;

int main(){
	std::ios::sync_with_stdio(false);
	int a=1,b=1;
	cin>>a;
	p=&a;
	*p--;
	cout<<a-b<<endl<<p;
	return 0;
}

