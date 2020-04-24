#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,m;

int main(){
	freopen("jout.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	n=64;m=88;
	cout<<n<<" "<<m<<endl;
	
	srand((unsigned)time(NULL));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<rand()%100000<<" ";
		}cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<rand()%100000<<" ";
		}cout<<endl;
	}
	return 0;
}

