#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
#define maxm 1001
bool vis[3][maxm];
int e[maxm][maxm];
int cnt,n;

void dfs(int h){
	if(h>n){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){  //�����ֱ��ʹ��һ�б�ʾһ����
		//��һ���Ǳ�ʾ�У��ڶ����Ǳ�ʾ�������·��򣬵��������������·���ֱ�ӱ�ʾһ����б�߻�ֱ�ߣ� 
		if(vis[0][i]==0 && vis[1][n+h-i]==0 && vis[2][h+i]==0){
			e[h][i]=vis[0][i]=vis[1][n+h-i]=vis[2][h+i]=1;
			dfs(h+1);
			e[h][i]=vis[0][i]=vis[1][n+h-i]=vis[2][h+i]=0; 
		}   
	}
	return;
}

int main(){
	memset(e,0,sizeof(e));
	memset(vis,0,sizeof(e));
	std::ios::sync_with_stdio(false);
	cin>>n; 
	dfs(1);
	cout<<cnt; 
	return 0;
}

