#include<iostream>
using namespace std;

void swap(int x,int y){
	int t;
	t=x;x=y;y=t;
	return;
}

int main(){
	int a=3,b=4;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}

