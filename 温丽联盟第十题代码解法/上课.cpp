#include<bits/stdc++.h>
using namespace std;
const long long maxm=1001;
const long long inf=0x3f3f3f;
int judge;
int main(){
	std::ios::sync_with_stdio(false);
	printf("������ţ�"); 
	scanf("%d",&judge);
	switch(judge){
		case 1:{  //������ַ��� 
			char c[maxm]={0};
			scanf("%s",c);
			int l=0,r=strlen(c)-1,len=strlen(c);
			while(l<r)
				if(c[l++]!=c[r--]){printf("���ǻ���");goto FINISH;}
			if(len&1) printf("�������"); 
			else printf("��ż����");
			break;
		}	
		case 2:{  //������� 
			long long num;int a[maxm]={0},len=0; 
			cin>>num;
			while(num>0){
				a[++len]=num%10;
				num/=10;
			}int l=1,r=len;
			while(l<r)
				if(a[l++]!=a[r--]){printf("���ǻ�����");goto FINISH;}
			if(len&1) printf("���������"); 
			else printf("��ż������");
			break;
		}
		case 3:{  //��������С 
			int a[maxm],n,ma=-1,mi=inf,k1,k2;
			k1=k2=0;
			scanf("%d",&n);  //�����ܳ� 
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]); 
				if(a[i]>ma){ma=a[i];k1=i;}
				if(a[i]<mi){mi=a[i];k2=i;}
			}printf("����λ�ã�%d����С��λ�ã�%d",k1,k2);
			break;
		}
		case 4:{  //���ʽ��� 
			int n,time=0;char c[maxm][maxm];
			memset(c,0,sizeof(c));
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%s",c[i]);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;  //Ҳ����ֱ��goto��forѭ����β
					int head=0,k;bool flag=false;  //head�Ǳ�ƥ�䵥�ʵ�ָ�� ��Ĭ��λ��ͷ�� 
					for(k=1;k<=strlen(c[i])-1;k++)
						if(c[i][k]==c[j][head]){
							head++;flag=true;
						}else flag=false;
					if(head<strlen(c[j])-1 && flag) time++;
				}
			}printf("%d",time);
			break;
		}
	}
	FINISH:return 0;
}
