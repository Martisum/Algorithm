#include<iostream>
#include<cstring>
using namespace std;
#define maxm 10001  //��������� 
int vis[maxm];  //�Ƿ��ѹ� 
struct edge{
	int u,v,next;  
}e[maxm];  
int head[maxm];  
int cx[maxm],cy[maxm];  //��ʾ���ұ�ƥ��ĵ�
int nl,nr;  //���ҵ������ 
int p,s,a,b,js;   
int lefts[maxm];  //�洢��ߵ��� 

void addedge(int u,int v){
	e[++js].u=u;
	e[js].v=v;
	e[js].next=head[u];
	head[u]=js; 
	return;
}

bool dfs(int u){ 
	vis[u]=1;  //��ǵ�ǰ���ѱ��ѹ�  
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(!vis[v]){
			vis[v]=1;
			if(!cy[v] || dfs(cy[v])){
				cy[v]=u;
				cx[u]=v;
				return 1;				
			}
		}
	}
	return 0;
}

int main(){
	freopen("hin.txt","r",stdin);
	cin>>p>>s;  
	cin>>nl>>nr;  //������������ҵ���
	for(int i=1;i<=s;i++){  
		cin>>a>>b;  
		addedge(a,b);  //˫��ߴ�2�� 
		addedge(b,a);
	} 
	for(int i=1;i<=nl;i++) cin>>lefts[i];
	
	//ִ���������㷨 
	int ans=0;
	for(int i=1;i<=nl;i++){
		dfs(lefts[i]);
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=p;i++){
		cout<<cx[i]<<"��"<<i<<endl;
	}
	return 0;
} 


















