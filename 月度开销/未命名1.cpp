#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,a[100009],maxx=0,tot,ans;

bool check(int x){  //����Сֵ��xʱ�Ƿ����
    int sum=0,yfen=1;
    for(int i=1;i<=n;i++){
        if(sum+a[i]>x){  //sum��һֱ�ۼӣ�������xʱ�·�++��˵����һ���Լ���һ���·�
            sum=a[i];
            yfen++;
        }
        else sum+=a[i];
   }if(yfen<=m) return 1;  //�·ݵ���mʱ���÷ֳ�m���·ݣ�С��mʱ�����Խ�ĳЩ�·��е�������������·ݣ�����ֳ�m���·� 
   else return 0;
}

int main(){
    scanf("%d%d",&n,&m);//����n�죬m���������� 
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot+=a[i];//���ֵ��Ҷ˵����ܵĿ��� 
        if(a[i]>maxx) maxx=a[i];//���ֵ���˵���n�������Ŀ��� 
    }
    
    int l=maxx,r=tot,mid;
    while(l<=r){  //���ֲ���
        mid=(l+r)>>1;
        if(check(mid)){  //����м�ֵ����
            ans=mid;  //��¼�� 
            r=mid-1;  //��С��Χ 
        }
        else l=mid+1; //��������Χ 
    }
    printf("%d",ans);  //�����Сֵ 
}

