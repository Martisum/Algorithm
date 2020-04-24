#include<iostream>
using namespace std;
int a,result=1;

int f(int x){
	if(x<=1) return 1;
	else return x*f(x-1);
}

int main(){
	cin>>a;
	cout<<f(a)<<endl;
	return 0;
}
