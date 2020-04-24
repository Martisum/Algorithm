#include<iostream>
using namespace std;
const int maxm=1001;
int e[maxm][maxm],p,s,a,b,begin;
int stack[maxm],cnt;  //创建栈 
int book[maxm]; //深搜标记数组 

void dfs(int start){
	stack[++cnt]=start;
	book[start]=1;
	while(stack[1]!=0){
		for(int i=1;i<=p;i++){
			if(e[stack[cnt]][i]==1 && book[i]==0){
				book[i]=1;
				stack[++cnt]=i;
				for(int t=1;t<=cnt;t++){
					cout<<stack[t]<<" ";
				}cout<<endl;
				i=1;
			}
		}
		stack[cnt]=0;cnt--;
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
	freopen("CON","r",stdin);
	
	cin>>begin;
	dfs(begin);
	return 0;
}
