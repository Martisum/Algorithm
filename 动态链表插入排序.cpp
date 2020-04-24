#include<bits/stdc++.h>
using namespace std;
vector<int> data;
int n;
int main(){
	freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	
	//ºËĞÄ´úÂë 
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(data[i]>data[j]){
				data.insert(data.begin()+j,data[i]);
				data.erase(data.begin()+i);
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++) cout<<data[i]<<endl;
	return 0;
}
