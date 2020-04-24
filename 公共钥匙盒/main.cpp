#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxm=1001;
int N,K;
int w,s,c,js[maxm]={0};
struct time_table{
	int key=0;
	bool get=false;
};struct time_table t[maxm][maxm];
int emp[maxm],loc[maxm],head,tail;

//void p(int t,int loc){
//	cout<<
//	return;
//}

int main(){
	freopen("gin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=maxm-1;i++)
		loc[i]=i;
	
	cin>>N>>K;
	for(int i=1;i<=K;i++){
		cin>>w>>s>>c;
		
		t[s][++js[s]].key=w;
		t[s][js[s]].get=true;
		int k=js[s];
		while(t[s][k-1].get==false&&t[s][k-1].key){swap(t[s][k],t[s][k-1]);k--;}
		while(t[s][k].key<t[s][k-1].key&&t[s][k].get==t[s][k-1].get){swap(t[s][k],t[s][k-1]);k--;}
		
		t[s+c][++js[s+c]].key=w;t[s+c][js[s+c]].get=false;
		k=js[s+c];
		while(t[s+c][k].key<t[s+c][k-1].key&&t[s+c][k].get==t[s+c][k-1].get){swap(t[s+c][k],t[s+c][k-1]);k--;}	
	}
	
//	for(int i=1;i<=45;i++){
//		cout<<"时刻"<<i<<": ";
//		for(int j=1;j<=js[i];j++){
//			if(t[i][j].key){
//				if(t[i][j].get) cout<<"取用";
//				else cout<<"归还"; 
//				cout<<"钥匙"<<t[i][j].key<<" ";
//			}
//		}
//		cout<<endl;
//	}
	
	for(int i=1;i<=maxm-1;i++){
		for(int j=1;j<=js[i];j++){
			if(t[i][j].key){
				if(t[i][j].get){
					emp[++head]=loc[t[i][j].key];
					int k=head;
					while(emp[k]<emp[k-1]&&k>tail+1){swap(emp[k],emp[k-1]);k--;}
					loc[t[i][j].key]=0;
				}else loc[t[i][j].key]=emp[++tail];	
			}	
		}
	}
	
	for(int i=1;i<=N;i++)
		cout<<loc[i]<<" ";
	return 0;
}
