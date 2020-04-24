#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=10001;
int p,s; 
int a,b,c;
struct e{
	int u,v,order,s;
	e(){u=v=order=0;return;}
	bool operator < (const e &x)const{
		if(s<x.s) return 1;
		return 0;
	}
}edge[maxm];

int js;
void addedge(int u,int v,int s,int order){  //这不是邻接表！ 
	edge[++js].u=u;
	edge[js].v=v;
	edge[js].s=s;
	edge[js].order=order;
	return;
} 

int fa[maxm];
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y){
	x=get(x);y=get(y);
	if(x!=y) fa[y]=x;
	return;
} 

int time;
void kruskal(){
	sort(edge+1,edge+s+1);
	for(int i=1;i<=s;i++){
		if(time==p-1) break;
		if(get(edge[i].u)!=get(edge[i].v)){
			merge(edge[i].u,edge[i].v);
			cout<<edge[i].u<<" link with "<<edge[i].v<<endl;
			time++;
		}
	} 
	return;
}

int main(){
	freopen("kin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		cin>>a>>b>>c;
		addedge(a,b,c,i);
	}for(int i=1;i<=p;i++)
		fa[i]=i;
	
	kruskal();
	return 0;
}
