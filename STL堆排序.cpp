#include<bits/stdc++.h>
using namespace std; 
vector<int> heap;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		heap.push_back(t);
	}make_heap(heap.begin(),heap.end(),cmp);
	for(int i=1;i<=n;i++){
		cout<<heap[0]<<endl;
		heap.erase(heap.begin(),heap.begin()+1);
		make_heap(heap.begin(),heap.end(),cmp);
	}
	return 0;
}
