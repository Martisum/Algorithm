#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main(){
	freopen("sin2.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	cout<<15<<endl;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=i;j++){
//			srand((unsigned)time(NULL));
			cout<<rand()%1000<<" ";
		}cout<<endl;
	}
	return 0;
}

