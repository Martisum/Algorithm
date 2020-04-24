#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=50;
int d[maxm],f[maxm],cnt,tot,ans;
bool flag,fm[maxm];

int main(){
	freopen("lin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	while(cin>>d[++cnt]);
	cnt--;
	for(int i=1;i<=cnt;i++) f[i]=1;
	for(int i=2;i<=cnt;i++){
		for(int j=1;j<=i-1;j++){
			if(d[i]<=d[j]){f[i]=max(f[i],f[j]+1);}
//			else{f[i]=max(f[i],f[j]);}
		}
	}
	for(int i=1;i<=cnt;i++){tot=max(tot,f[i]);}
	
	
	do{
		int p=1;
		while(fm[p]) p++;
		if(p>cnt) break;
		ans++;
		for(int i=p;i<=cnt;i++){
			if(d[p]>=d[i]&&fm[i]==0){
				fm[i]=1;
				p=i;
			}
		}
	}while(1);
	
	cout<<tot<<endl<<ans;
	return 0;
}
