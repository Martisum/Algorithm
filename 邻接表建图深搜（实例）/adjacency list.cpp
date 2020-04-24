#include<cstdio>
#include<iostream>
using namespace std;
const int maxm=1001;
int p,s,a,b;

struct edge{
	int u,v,next;
}e[maxm];
int head[maxm],js;
int book[maxm];

void addedge(int u,int v){
	e[++js].u=u;
	e[js].v=v;
	e[js].next=head[u];
	head[u]=js;
	return;
}

void dfs(int x){
	book[x]=1;
	for(int i=head[x];i;i=e[i].next){
		if(book[e[i].v]!=1){
			cout<<e[i].u<<"to"<<e[i].v<<endl;
			dfs(e[i].v);
		}
	}
	return;
}

int main(){
	freopen("ain.txt","r",stdin);
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		cin>>a>>b;
		addedge(a,b);
	}
	freopen("CON","r",stdin);
	
	int start;
	cin>>start;
	dfs(start);
	
//	for(int i=1;i<=p;i++){
//		cout<<"点"<<i<<"连出去的所有点为："; 
//		for(int j=head[i];j;j=e[j].next) cout<<e[j].v<<" ";
//		cout<<endl;
//	}
	return 0;
} 
