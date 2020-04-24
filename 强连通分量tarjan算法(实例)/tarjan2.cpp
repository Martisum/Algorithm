#include<iostream>
using namespace std;
const int maxm=1001;
int e[maxm][maxm],p,s,a,b,begin;
int stack[maxm],cnt;  //创建栈 
int book[maxm]; //深搜标记数组 
int dfn[maxm],low[maxm],tot; //tarjan算法的时间戳和Low。 


void dfs(int start){
	stack[++cnt]=start;
	book[start]=1;
	
	tot++;
	dfn[start]=low[start]=tot;
	
	while(stack[1]!=0){
		LOOP:for(int i=1;i<=p;i++){
			if(e[stack[cnt]][i]==1 && book[i]==0){
				book[i]=1;
				stack[++cnt]=i;
				
				tot++;
				dfn[i]=low[i]=tot;
				
				for(int t=1;t<=cnt;t++){
					cout<<stack[t]<<" ";
				}cout<<endl;
				goto LOOP;
			}
		}
		
		SEC:for(int i=1;i<=p;i++){
			if(e[stack[cnt]][i]==1 && low[stack[cnt]]>low[i]){
				low[stack[cnt]]=low[i];
				stack[cnt]=0;cnt--;
				goto SEC;
			}
		}
		
		stack[cnt]=0;cnt--;
	}
	return;
}

int main(){
	freopen("tin.txt","r",stdin);
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
