#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=1001;

int x[1000];
int k=0,n;
int a[100],b[100],c[100],d[100];

void search(int i){
	if(i>n){
		k++;
		return;
	}
	else for(int j=1;j<=n;j++){
		if(a[j]==0&&b[i-j+30]==0&&c[i+j]==0){
			x[i]=j;
			d[i]=c[i+j]=a[j]=b[i-j+30]=1;
			search(i+1);
			d[i]=c[i+j]=a[j]=b[i-j+30]=0;
		}
	}
	return;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	search(1);
	cout<<k;
	return 0;
}
