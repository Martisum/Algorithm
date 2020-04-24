#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxm 1001
char a[maxm],b[maxm];
int ans,lena,lenb,lenc;
bool flag=0;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	lenb=strlen(b);lena=strlen(a);
	lenc=min(lena,lenb);
	
	for(int i=1;i<=lenc-1;i++){
		for(int j=i,k=0;j<=lena-1 && k<=lenb-1;k++,j++){
			if(a[j]==b[k]){
				ans++;
				if(j==lena-1){flag=1;}
				continue;
			}
			break; 
		}
		if(flag) break;
		ans=0;
	}
	
	cout<<ans;
	return 0;
}


