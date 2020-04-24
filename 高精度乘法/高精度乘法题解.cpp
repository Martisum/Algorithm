#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define maxm 2019
int main(){
//	freopen("gin.txt","r",stdin);
    char a1[maxm],b1[maxm];
    int a[maxm],b[maxm],c[maxm],lena,lenb,lenc,i,j,x;
    cin>>a1>>b1;
    lena=strlen(a1);lenb=strlen(b1);
    for (i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;
    for (i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;
    for (i=1;i<=lena;i++){
         x=0;                                               
         for (j=1;j<=lenb;j++){
            c[i+j-1]=a[i]*b[j]+x+c[i+j-1];      
            x=c[i+j-1]/10;
            c[i+j-1]%=10;
         }
         c[i+lenb]=x;                                  
    }
    lenc=lena+lenb;
    while (c[lenc]==0&&lenc>1)       
        lenc--;
    for (i=lenc;i>=1;i--)
        cout<<c[i];
    cout<<endl;
    return 0;
}
