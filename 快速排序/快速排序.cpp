#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1000001
int n,a[maxm]; 

void quicksort(int l,int r){
	int flag=r,tl=l,tr=r;
	while(tl<tr){
		while(a[tl]<=a[flag]&&tl<tr) tl++;
		while(a[tr]>=a[flag]&&tl<tr) tr--;
		if(a[tl]>a[tr]) swap(a[tl],a[tr]);
	}swap(a[tl],a[flag]);
	flag=tl;
	if(l<flag-1) quicksort(l,flag-1);
	if(flag+1<r) quicksort(flag+1,r);
	return;
}

int main(){
	freopen("qin.txt","r",stdin); 
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	quicksort(1,n);
	
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

