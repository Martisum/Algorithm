#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define mmax 10001
#define inf 10001
int n,data[mmax],heap[mmax],t;
//void track(int s){
//	cout<<"当前状态该变量："<<s<<endl;
//	return;
//}
void add(int index){
	if(index!=1 && heap[index]<heap[index>>1]){
		swap(heap[index],heap[index>>1]);
		add(index>>1);
	}
	return;
}
void out(int index){
//	track(heap[index]);
	if(index<=n){
		if(heap[index]>=heap[index<<1] && heap[index<<1]<=heap[(index<<1)+1]){
			swap(heap[index],heap[index<<1]);
			out(index<<1);
		}if(heap[index]>=heap[(index<<1)+1]){
			swap(heap[index],heap[(index<<1)+1]);
			out((index<<1)+1);
		}
	}
	return;
}
int main(){
	freopen("in.txt","r",stdin);
	cin>>n;
	memset(heap,inf,sizeof(heap));
	for(int i=1;i<=n;i++){
		cin>>heap[i];
		add(i);
	}
	
	//核心代码 
//	out(1);
	for(int i=1;i<=n;i++){
		data[i]=heap[1];heap[1]=inf;
		out(1);
	}
	
	for(int i=1;i<=n;i++) cout<<data[i]<<endl;
	return 0;
}
