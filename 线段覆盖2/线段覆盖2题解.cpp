#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
struct node{
    int l,r,c;
    node(int l=0,int r=0,int c=0):l(l),r(r),c(c){}
    bool operator <(const node &a)const{
        return r<a.r;
    }
};
node seg[maxn];
int f[maxn],n;

void init(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        seg[i]=node(l,r,c);
    }
}

void dp(){
    sort(seg+1,seg+n+1);
    for (int i=1;i<=n;++i)
      f[i]=seg[i].c;
    for (int i=2;i<=n;++i)
      for (int j=1;j<=i-1;++j)
        if (seg[j].r<=seg[i].l){
            f[i]=max(f[i],f[j]+seg[i].c);
        }
    int ans=0;
    for(int i=1;i<=n;++i)
      ans=max(ans,f[i]);
    printf("%d",ans);
}

int main(){
	freopen("xin.txt","r",stdin); 
    init();
    dp();
    return 0;
}
