#include<iostream>
using namespace std;
int a[100],i;

//第一题：读入10个数字然后输出10个数字 
//第二题: 如果仅仅输出1到10的所有奇数怎么办？？？ 
int main(){
	std::ios::sync_with_stdio(false);
//	i=1;
//	while(i<=10){
//		cin>>a[i];
//		i=i+1;
//	}
//	
//	i=1;
//	while(i<=10){
//		cout<<a[i]<<" ";
//		i=i+1;
//	}
	
	
//	for(i=1;i<=10;i=i+1){
//		cin>>a[i];
//	}
//	for(i=1;i<=10;i++){
//		cout<<a[i]<<" ";
//	}

  //提前进入下一个循环 

	for(i=1;i<=10;i++){
		if(i==1 || i%2==0) continue;
		else if(i%2) cout<<i<<" ";
	}
	
	return 0;
}
