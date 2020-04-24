#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxm=1001;

int main(){
	int n;
	char ss[maxm];
	cin>>n>>ss;
	for (int i=0;i<=strlen(ss)-1;i++){
		if (ss[i]+n>'z'){
			ss[i]+=n-26;
			continue;
		}ss[i]+=n;
	}	
	cout<<ss<<endl;
	return 0;
}

