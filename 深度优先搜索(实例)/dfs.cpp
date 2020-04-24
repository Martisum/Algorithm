#include<iostream>
using namespace std;
const int maxm=1001;
int e[maxm][maxm],color[maxm],p,s,a,b,begin;  //创建邻接矩阵 

void dfs(int start){
//	if(start==6) return;
	for(int i=1;i<=p;i++){
		if(i==3 || i==4) continue;
		if(e[start][i]&&!color[i]){
			color[i]=1;
			cout<<start<<" "<<i<<endl;
			dfs(i);  //搜索下一个点 
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
	color[begin]=1;  //标记搜索过的点 
	dfs(begin);
	return 0;
}
