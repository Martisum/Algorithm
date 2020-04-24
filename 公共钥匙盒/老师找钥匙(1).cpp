#include<iostream>
#include<time.h>
using namespace std;
long start,end;
int main(){
	start=clock();
	freopen("gin.txt","r",stdin);
	int N,n,K,overtime=0;
	cin>>N>>K;
	int *borrowtime=new int[K],*backtime=new int[K],*keyID=new int[K], *keys=new int[N];
	for (n=0;n<N;n++)
		keys[n]=n+1;//创建钥匙盒 
	for(int i=0;i<K;i++){
		cin>>keyID[i]>>borrowtime[i]>>backtime[i];//输入钥匙编号，取钥匙时刻，使用钥匙时长 
		backtime[i]=borrowtime[i]+backtime[i];//获取还钥匙时刻 
		if(backtime[i]>overtime)overtime=backtime[i];//最后一次还钥匙的时间 
	}
	for(int i1=1;i1<=overtime;i1++){//遍历时间 
		for(int j=0;j<K;j++) {//遍历老师 
			if(backtime[j]==i1){ // 当对应上换钥匙时间 
				for(int n1=0;n1<N;n1++){//遍历钥匙盒 
					if(keys[n1]==0)	{//找到最左边的空钥匙 
								
						keys[n1]=keyID[j];//归还钥匙 
						break;	}													
				}
				
			
			}if(borrowtime[j]==i1){//当对应上借钥匙时间 
				for(int n2=0;n2<N;n2++){//遍历钥匙盒 
					if(keys[n2]==keyID[j])//找到需要的钥匙 
						keys[n2]=0;//取用钥匙 
				}
			}
				
			
			
	    }
	}for(int n3=0;n3<N;n3=n3+1) 
	cout<<keys[n3];
	
	end=clock();
	cout<<endl<<end-start;
	return 0;
}
	
	
