#include<iostream>
using namespace std;
int a[100],i;

//��һ�⣺����10������Ȼ�����10������ 
//�ڶ���: ����������1��10������������ô�죿���� 
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

  //��ǰ������һ��ѭ�� 

	for(i=1;i<=10;i++){
		if(i==1 || i%2==0) continue;
		else if(i%2) cout<<i<<" ";
	}
	
	return 0;
}
