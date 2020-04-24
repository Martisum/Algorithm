#include<bits/stdc++.h>
using namespace std;
#define maxm 1001
int fa[maxm],n,order[maxm],p;
struct pointform{
	int from;
	int to;
	int edge;
};
struct pointform pmap[maxm];
bool cmp(int x,int y){
	return pmap[x].edge<pmap[y].edge;
} 
int get(int x){
	if(fa[x]==x){
		return x;
	}return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y) fa[y]=x;
	return;
}
void kruskal(){
	int time=0;
	sort(order+1,order+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(time==p-1) break;
		if(get(pmap[order[i]].from)!=get(pmap[order[i]].to)){
			merge(pmap[order[i]].from,pmap[order[i]].to);
			cout<<pmap[order[i]].from<<" "<<pmap[order[i]].to<<endl;
			time++;
		}
	}
	cout<<time;
	return;
}
int main(){
	freopen("kin.txt","r",stdin);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		order[i]=i;
		fa[i]=i;
	}
	for(int i=1;i<=n;i++) cin>>pmap[i].from>>pmap[i].to>>pmap[i].edge;
	freopen("CON","r",stdin);
	
	kruskal();
//	for(int i=1;i<=n;i++) cout<<order[i]<<endl;
	return 0;
}
