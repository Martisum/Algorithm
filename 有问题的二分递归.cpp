#include<bits/stdc++.h>
using namespace std;
#define maxn 1001
int data[maxn],n,target;

int search(int head,int tail){
	if(data[(head+tail)>>1]>target) return search(head,((head+tail)>>1)-1);
	if(data[(head+tail)>>1]<target) return search(((head+tail)>>1)+1,tail);
	if(tail==(head+tail)>>1 && tail!=target) return 0;
	return (head+tail)>>1;
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	sort(data+1,data+n+1);
	
	freopen("CON","r",stdin);
	cin>>target;
	
	cout<<search(1,n)<<endl;
	return 0;
}
