#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
struct node{
	int l,r,v;
	bool operator < (const node &x)const{
		if(l<x.l) return 1;
		return 0;
	}
}line[maxm];
int n,f[maxm],ans;

int main(){
	freopen("xin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>line[i].l>>line[i].r>>line[i].v;
	
	sort(line+1,line+n+1);
	for(int i=1;i<=n;i++)
		f[i]=line[i].v;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			if(line[i].l>=line[j].r){
				f[i]=max(f[i],f[j]+line[i].v);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	
	cout<<ans;
	return 0;
}
