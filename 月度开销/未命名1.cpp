#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,a[100009],maxx=0,tot,ans;

bool check(int x){  //当最小值是x时是否可以
    int sum=0,yfen=1;
    for(int i=1;i<=n;i++){
        if(sum+a[i]>x){  //sum是一直累加，当超过x时月份++，说明这一天自己另一个月份
            sum=a[i];
            yfen++;
        }
        else sum+=a[i];
   }if(yfen<=m) return 1;  //月份等于m时正好分成m个月份，小于m时，可以将某些月份中的天数拆开组成新月份，满足分成m个月份 
   else return 0;
}

int main(){
    scanf("%d%d",&n,&m);//输入n天，m个财政周期 
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot+=a[i];//二分的右端点是总的开销 
        if(a[i]>maxx) maxx=a[i];//二分的左端点是n天中最大的开销 
    }
    
    int l=maxx,r=tot,mid;
    while(l<=r){  //二分查找
        mid=(l+r)>>1;
        if(check(mid)){  //如果中间值可以
            ans=mid;  //记录答案 
            r=mid-1;  //缩小范围 
        }
        else l=mid+1; //否则扩大范围 
    }
    printf("%d",ans);  //输出最小值 
}

