#include<bits/stdc++.h>
using namespace std;
#define mmax 10001
int n,data[mmax],book[mmax];
int main(){
	freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	
	//核心代码
	for(int i=1;i<=n;i++) book[data[i]]++;
	//非优化版，假设排序数的数据最大是100,但是数据较大时反而不划算； 
	int t=1;
	for(long long i=1;i<=100000;i++){
		if(book[i]!=0) data[t++]=i;
	}  
//	int maxs=0,t=1;
//	for(int i=1;i<=n;i++) maxs=max(maxs,data[i]);
//	for(int i=1;i<=maxs;i++){
//		if(book[i]!=0) data[t++]=i;
//	} 
	for(int i=1;i<=n;i++) cout<<data[i]<<endl;
	return 0;
}
