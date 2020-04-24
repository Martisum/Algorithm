#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const long long maxn=10001;
int e[maxn][maxn],target,sum;
int t=1;


int main(){
//	freopen("in.txt","r",stdin);
	cin>>target;
	e[0][0]=1;
	while(e[t-1][t-1]<target){
		e[t][t]=e[t-1][t-1]+sum;
		sum=sum+4;
		t++;
	}t--;
	
	int i,j;
	if(e[t][t]==target || e[t-1][t]==target){
		cout<<i<<"/"<<j;
		return 0;
	}
	i=t-1;j=t-1;
	while(i!=1){
		e[i-1][j+1]=e[i][j]+1;
		if(e[i-1][j+1]==target){
			cout<<i<<"/"<<j;
			return 0;
		}
		i--;j++;
	}j++;
	
	e[i][j]=e[i][j-1]+1;
	if(e[i][j]==target){
			cout<<i<<"/"<<j;
			return 0;
		}
	
	while(j!=1){
		e[i+1][j-1]=e[i][j]+1;
		if(e[i+1][j-1]==target){
			cout<<i<<"/"<<j;
			return 0;
		}
		i++;j--;
	}i++;
	
	e[i][j]=e[i-1][j]+1;
	if(e[i][j]==target){
			cout<<i<<"/"<<j;
			return 0;
		}
	
	while(i!=1){
		e[i-1][j+1]=e[i][j]+1;
		if(e[i-1][j+1]==target){
			cout<<i<<"/"<<j;
			return 0;
		}
		i--;j++;
	}
//	for(int i=1;i<=10;i++) cout<<e[i][i]<<endl;
	return 0;
}
