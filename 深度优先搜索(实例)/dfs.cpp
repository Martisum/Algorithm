#include<iostream>
using namespace std;
const int maxm=1001;
int e[maxm][maxm],color[maxm],p,s,a,b,begin;  //�����ڽӾ��� 

void dfs(int start){
//	if(start==6) return;
	for(int i=1;i<=p;i++){
		if(i==3 || i==4) continue;
		if(e[start][i]&&!color[i]){
			color[i]=1;
			cout<<start<<" "<<i<<endl;
			dfs(i);  //������һ���� 
		}
	}
	return;
}

int main(){
	freopen("dfsin.txt","r",stdin);
	cin>>p>>s;
	for(int i=1;i<=s;i++){
		cin>>a>>b;
		e[a][b]=1;
	}
//	freopen("CON","r",stdin);
	
	cin>>begin;
	color[begin]=1;  //����������ĵ� 
	dfs(begin);
	return 0;
}
