#include<iostream>
#include<algorithm>
using namespace std;
int m,n,mins;

int main(){
	cin>>m>>n;
	mins=min(m,n);
	for(int i=2;i<=mins;i++){
		while(m%i==0 && n%i==0){
			m/=i;n/=i;
			mins/=i;
		}
	}
	cout<<m<<"/"<<n<<endl;
	return 0;
}
