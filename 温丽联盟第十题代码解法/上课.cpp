#include<bits/stdc++.h>
using namespace std;
const long long maxm=1001;
const long long inf=0x3f3f3f;
int judge;
int main(){
	std::ios::sync_with_stdio(false);
	printf("输入题号："); 
	scanf("%d",&judge);
	switch(judge){
		case 1:{  //求回文字符串 
			char c[maxm]={0};
			scanf("%s",c);
			int l=0,r=strlen(c)-1,len=strlen(c);
			while(l<r)
				if(c[l++]!=c[r--]){printf("不是回文");goto FINISH;}
			if(len&1) printf("是奇回文"); 
			else printf("是偶回文");
			break;
		}	
		case 2:{  //求回文数 
			long long num;int a[maxm]={0},len=0; 
			cin>>num;
			while(num>0){
				a[++len]=num%10;
				num/=10;
			}int l=1,r=len;
			while(l<r)
				if(a[l++]!=a[r--]){printf("不是回文数");goto FINISH;}
			if(len&1) printf("是奇回文数"); 
			else printf("是偶回文数");
			break;
		}
		case 3:{  //求最大和最小 
			int a[maxm],n,ma=-1,mi=inf,k1,k2;
			k1=k2=0;
			scanf("%d",&n);  //输入总长 
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]); 
				if(a[i]>ma){ma=a[i];k1=i;}
				if(a[i]<mi){mi=a[i];k2=i;}
			}printf("最大的位置：%d，最小的位置：%d",k1,k2);
			break;
		}
		case 4:{  //单词接龙 
			int n,time=0;char c[maxm][maxm];
			memset(c,0,sizeof(c));
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%s",c[i]);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;  //也可以直接goto到for循环结尾
					int head=0,k;bool flag=false;  //head是被匹配单词的指针 ，默认位于头部 
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
