#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
int a,b;
struct node{
	int x,y;
	
}; 
struct node str;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	str=node(a,b);
	cout<<str.x<<" "<<str.y;
	return 0;
}
