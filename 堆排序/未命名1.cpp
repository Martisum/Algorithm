#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=10001;
int heap[maxm],n;

int compare(int a,int b){
	if(heap[a]>=heap[b]) return a;
	return b;
}

void reset(int x){
	if(heap[x]<compare(x<<1,(x<<1)+1)){
		int t=compare(x<<1,(x<<1)+1);
		swap(t,heap[x]);
		reset(compare(x<<1,(x<<1)+1));
	}
	return;
}

int main(){
//	freopen("hin.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>heap[i];
	for(int i=1;i<=n;i++){
		reset(1);cout<<heap[1]<<" ";
		heap[1]=0;
	}
	return 0;
}
