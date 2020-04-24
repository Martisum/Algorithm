#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm=101
struct node{
	char a[maxm];
	int order;
}w[maxm];
char tar;
int n;

void dfs(int x){
	char ed=w[x].a[strlen(w[x].a)-1];
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=strlen(w[i].a)-2;j++){
			if(ed==w[i].a[j]){
				
			}
		}
	}
	return;
}

int main(){
	freopen("jin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i].a;
		w[i].order=i;
	}
	cin>>tar;
	
	for(int i=1;i<=n;i++){
		if(a[i][0]==tar){
			dfs(w[i].order);
		}
	}
	return 0;
}

