#include<iostream>
using namespace std;

void addnum(int *x,int *y){
	*x+=1;*y+=1;
	return;
}

int func(int a){return a+5;}

int main(){
	int x=1,y=2;
	addnum(&x,&y);
	cout<<x<<" "<<y<<endl;
	return 0;
}

