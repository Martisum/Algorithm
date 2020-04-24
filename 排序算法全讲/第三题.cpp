#include<iostream>
#include<iomanip>
using namespace std;


//自动类型转换 
//char->int 
//double/float->int

int main(){
	std::ios::sync_with_stdio(false);
	int d[10]={0,21,19,20,15,13,17};
	int n=6;
	for(int i=1;i<=n-1;i++){
		int k=i;
		for(int j=i+1;j<=n-1;j++)
			if(d[j]>d[k]) k=j;
		if(i!=k) swap(d[i],d[k]);
	}
	
	for(int i=1;i<=6;i++)
		cout<<d[i]<<" ";
	return 0;
}

