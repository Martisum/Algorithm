#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=1001;
const long long inf=0x3f3f3f;
int n,d[maxm];

int tl,tr,tms;
void find_max_crossing_subarray(int l,int r){
	int left_sum=-inf,sum=0,max_left=0;
	int mid=(l+r)>>1;
	for(int i=mid;i>=l;i--){
		//cout<<sum<<endl; 
		sum+=d[i];
		if(sum>left_sum){
			//cout<<1<<endl;
			left_sum=sum;
			max_left=i;
		}
	}
	
	tms+=left_sum;
	//cout<<tms<<endl;
	sum=0;
	int right_sum=-inf,max_right=0;
	for(int i=mid+1;i<=r;i++){
		sum+=d[i];
		if(sum>right_sum){
			right_sum=sum;
			max_right=i;
		}
	}
	
	tl=max_left;
	tr=max_right;
	tms+=right_sum;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	freopen("min.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	
	find_max_crossing_subarray(1,n);
	cout<<tl<<" "<<tr<<" "<<tms<<endl;
	return 0;
}
