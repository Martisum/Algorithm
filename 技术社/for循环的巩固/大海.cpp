#include<iostream>
#include<cstring>
using namespace std;
int e[20][20],a,b;

int main(){
	freopen("sin.txt","r",stdin);
	freopen("sout.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	memset(e,-1,sizeof(e));
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++)
			e[i][j]=0;
	}
	
	int m=1,n=1,time=1;
	e[m][n]=1;
	while(1){
		if(time>=100) break;
			for(int j=1;j<=10;j++)
					if(e[m][n+1]==0) e[m][++n]=++time;
			for(int j=1;j<=10;j++)
					if(e[m+1][n]==0) e[++m][n]=++time;
			for(int j=1;j<=10;j++)
					if(e[m][n-1]==0) e[m][--n]=++time;
			for(int j=1;j<=10;j++)
				if(e[m-1][n]==0) e[--m][n]=++time;
	}
	
	while(cin>>a>>b){
		if(e[a][b]<30) cout<<18<<":"<<e[a][b]+30<<endl;
		else if(e[a][b]<40) cout<<19<<":0"<<e[a][b]-30<<endl;
		else if(e[a][b]<90) cout<<19<<":"<<e[a][b]-30<<endl;
		else cout<<20<<":"<<e[a][b]-90<<endl;
	}
	
	
//	for(int i=1;i<=10;i++){
//		for(int j=1;j<=10;j++){
//			cout<<e[i][j]<<" ";
//		}cout<<endl;
//	}
	return 0;
}
