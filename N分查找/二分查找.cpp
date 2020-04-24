#include<iostream>
#include<cstdio>
using namespace std;
const long long maxm=0x3f3f3f;
int d[maxm],n,key;
int l,r;

int main(){
	std::ios::sync_with_stdio(false);
	freopen("ein.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	freopen("CON","r",stdin);
	scanf("%d",&key);
	
	l=1;r=n;
	while(l<=r){
		register int mid=(l+r)>>1;
		if(d[mid]==key){printf("%d",mid);break;}
		else if(key>d[mid]) l=mid+1;
		else r=mid; 
	}
	return 0;
}
