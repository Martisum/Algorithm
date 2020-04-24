#include<iostream>
using namespace std;
const int maxm=10001;
int n,d[maxm];

inline void swaps(int &m,int &n){
	int tmp;
	tmp=m;m=n;n=tmp;
	return;
}

void BubbleSort(int l,int r){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[j-1]>d[j]) swap(d[j-1],d[j]);
		}
	}
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	freopen("min.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	
	BubbleSort(1,n);
	
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	return 0;
}

