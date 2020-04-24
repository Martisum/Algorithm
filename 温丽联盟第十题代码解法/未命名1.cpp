#include<iostream>
using namespace std;
const int n=4;
int d[100]={0,1,2,3},q[100];

int main(){
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(q[i]<q[j]){
				d[i]=d[i]+d[j];
				d[j]=d[i]-d[j];
				d[i]=d[i]-d[j];
				swap(q[i],q[j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" "<<q[i]<<endl;
	}
	return 0;
}

