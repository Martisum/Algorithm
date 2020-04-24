#include<iostream>
#include<algorithm>
using namespace std;
#define maxm 1001
int s,p;  //������������� 
int e[maxm][maxm],stack[maxm],dfn[maxm],low[maxm],cnt,color[maxm];  //�ֱ�Ϊ����ͼ��tarjanջ��ʱ�������ʹ�����ʱ����������Ⱦɫ��
int fa[maxm];  //���岢�鼯 

//int get(int x){
//	if(fa[x]==x) return x;
//	return fa[x]=get(fa[x]);
//} 
//
//void merge(int x,int y){
//	x=get(x);y=get(y);
//	if(x!=y) fa[y]=x;
//	return;
//}

void tarjan(int begin){
	for(int i=1;i<=p;i++){
		if(color[i]==0 && low[i]!=1){
			dfn[i]=low[i]=++cnt;
			color[i]=1;
			tarjan(i);
			low[begin]=min(low[begin],low[i]);
		}if(color[i]==1 && low[i]==1){
			low[begin]=min(low[begin],low[i]);
			return;
		}
	} 
	return;
}

int main(){
	int a,b;
	freopen("tin.txt","r",stdin);
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		cin>>a>>b;
		e[a][b]=1;
	}
	freopen("CON","r",stdin);
	for(int i=1;i<=p;i++) fa[i]=i;  //��ʼ�����鼯 
	
	int start;
	cin>>start;
	color[start]=low[start]=dfn[start]=++cnt;
	tarjan(start);
//	cnt=0;
//	memset(stack,0,sizeof(stack));
//	memset(dfn,0,sizeof(dfn));
//	memset(low,0,sizeof(low));
//	memset(color,0,sizeof(color));
	
	for(int i=1;i<=p;i++){
		if(low[i]==1) cout<<i<<endl; 
	} 
	return 0;
}
