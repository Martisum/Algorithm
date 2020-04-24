#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1001;
int p,s,a,b;
int dfn[maxm],low[maxm],cnt;//ʱ�������С�������� 
int st[maxm],top; 
int color[maxm],col;//Ⱦɫ��ǿ��ͨ�������� 

struct edge{
	int u,v,next;
}e[maxm];
int head[maxm],js;

void addedge(int u,int v){
	e[++js].u=u;
	e[js].v=v;
	e[js].next=head[u];
	head[u]=js;
	return;
}

void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	st[++top]=u;
	for(int i=head[u];i;i=e[i].next){
		if(dfn[e[i].v]==0){
			tarjan(e[i].v);
			low[u]=min(low[u],low[e[i].v]);
		}
		else if(color[e[i].v]==0){
			low[u]=min(low[u],low[e[i].v]);
		}
	}
	if(low[u]==dfn[u]){
		color[u]=++col;
		while(st[top]!=u){
			color[st[top]]=col;
			top--;
		} 
		top--;
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
	tarjan(start);
	
	for(int i=1;i<=p;i++) cout<<color[i]<<endl;
	
//	for(int i=1;i<=p;i++){
//		cout<<"��"<<i<<"����ȥ�����е�Ϊ��"; 
//		for(int j=head[i];j;j=e[j].next) cout<<e[j].v<<" ";
//		cout<<endl;
//	}
	return 0;
} 
