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
		keys[n]=n+1;//����Կ�׺� 
	for(int i=0;i<K;i++){
		cin>>keyID[i]>>borrowtime[i]>>backtime[i];//����Կ�ױ�ţ�ȡԿ��ʱ�̣�ʹ��Կ��ʱ�� 
		backtime[i]=borrowtime[i]+backtime[i];//��ȡ��Կ��ʱ�� 
		if(backtime[i]>overtime)overtime=backtime[i];//���һ�λ�Կ�׵�ʱ�� 
	}
	for(int i1=1;i1<=overtime;i1++){//����ʱ�� 
		for(int j=0;j<K;j++) {//������ʦ 
			if(backtime[j]==i1){ // ����Ӧ�ϻ�Կ��ʱ�� 
				for(int n1=0;n1<N;n1++){//����Կ�׺� 
					if(keys[n1]==0)	{//�ҵ�����ߵĿ�Կ�� 
								
						keys[n1]=keyID[j];//�黹Կ�� 
						break;	}													
				}
				
			
			}if(borrowtime[j]==i1){//����Ӧ�Ͻ�Կ��ʱ�� 
				for(int n2=0;n2<N;n2++){//����Կ�׺� 
					if(keys[n2]==keyID[j])//�ҵ���Ҫ��Կ�� 
						keys[n2]=0;//ȡ��Կ�� 
				}
			}
				
			
			
	    }
	}for(int n3=0;n3<N;n3=n3+1) 
	cout<<keys[n3];
	
	end=clock();
	cout<<endl<<end-start;
	return 0;
}
	
	
