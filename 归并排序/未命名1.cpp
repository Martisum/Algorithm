#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=100005; 
int n,d[maxm],tmp[maxm];

void mergesort(int l,int r){
	if(l>=r) return;
	int mid=(l+r)>>1;
	mergesort(l,mid);
	mergesort(mid+1,r);
	
	int z=l,y=mid+1,p=l;
	while(z<=mid&&y<=r){
		if(d[z]<=d[y]) tmp[p++]=d[z++];
		else tmp[p++]=d[y++];
	}

	while(z<=mid) tmp[p++]=d[z++];
	while(y<=r) tmp[p++]=d[y++];
	for(int i=l;i<=r;i++)
		d[i]=tmp[i];
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	
	mergesort(1,n);
	
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	return 0;
}
