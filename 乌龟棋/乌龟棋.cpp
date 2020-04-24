#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=501;
int n,m,d[maxm],f[maxm],a,cnt,dir[maxm];
struct node{
	int num,time;
}c[maxm];

int get(int x){
	int ans=0;
//	if(f[x]) return f[x];
//	for(int i=1;i<=cnt;i++)
//		if(x==dir[i]) return f[x];
	if(x==1) return f[1];

	for(int i=1;i<=cnt;i++){
		if(c[dir[i]].num<c[dir[i]].time){
			c[dir[i]].num++;
			ans=max(f[x],get(x-dir[i])+d[i]);
			c[dir[i]].num--;
		}
	}
	cout<<"f["<<x<<"]="<<ans<<endl;
	return f[x]=ans;
}

int main(){
	freopen("win.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<=n-1;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++){
		cin>>a;
		if(!f[a]){f[a]=d[a];dir[++cnt]=a;}
		c[a].time++;
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<" ";
//	}cout<<endl;
//	
//	for(int i=1;i<=cnt;i++) cout<<dir[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=m;i++) cout<<c[i].time<<" ";
	int t=get(n-1)+d[0];
	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<endl;	
	cout<<t;
	return 0;
}

