#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include<time.h>
using namespace std;
long start,end;
struct T {
    int id;
    int _time;
};
const int N=1000+7;
int x[N],p[N];// x 模拟钥匙盒 x[i]=j 表示i位置放置j x[i]=0表示空
              // p[i]=j  i钥匙放置的位置是j
T t1[N],t2[N];// t1[] 表示 要借钥匙的请求 （id和时间） 
             //  t2[] 表示  要还的钥匙序号和时间 
int n1,n2;//  n1 表示下一个要借的钥匙
          //  n2 表示下一个要还的钥匙
int n,k;
bool cmp (T a, T b) {// 时间第一关键字 序号第二关键字
    if (a._time==b._time)
        return a.id<b.id;
    return a._time<b._time;
}
void re ( int id ) {// 找到第一个空位置还书
    for (int i=1;i<=n;i++)  
        if (x[i]==0) {
            x[i]=id;
            p[id]=i;
            break;
        }
    return ;
}
int main ()
{
	start=clock();
	freopen("gin.txt","r",stdin);
    scanf ("%d %d",&n,&k);
    for (int i=1;i<=n;i++) 
        x[i]=p[i]=i;
    for (int i=1;i<=k;i++) {
        int w,s,c;
        scanf ("%d %d %d",&w,&s,&c);
        T x1={w,s}; t1[i]=x1;
        T x2={w,s+c}; t2[i]=x2;
    }
    sort (t1+1,t1+1+k,cmp); n1=1;
    sort (t2+1,t2+1+k,cmp); n2=1;
    int _start=t1[1]._time;
    int _end=t2[k]._time;
    for (int i=_start;i<=_end;i++) {// 模拟时间的进行,进行活动的发生 
        while (n2<=k&&t2[n2]._time==i)  { re (t2[n2].id); n2++; }  //同一时间先还
        while (n1<=k&&t1[n1]._time==i)  { int pos=p[t1[n1].id]; x[pos]=0; n1++;}
    }
    for (int i=1;i<=n;i++)
        printf ("%d ",x[i]);
    printf ("\n");
    
    end=clock();
	cout<<endl<<end-start;
    return 0;
}
