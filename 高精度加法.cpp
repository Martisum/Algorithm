#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

const int maxm=1001;
char am[maxm],bm[maxm];
int a[maxm],b[maxm],c[maxm];
int la,lb,totl,flag,lat,lbt;

int main(){
	freopen("gin.txt","r",stdin);
	gets(am);gets(bm);
	lat=la=strlen(am);
	lbt=lb=strlen(bm);
	
	if(la>=lb) totl=la;
	else totl=lb;
	
	int it=totl;
	while(lat&&it>=1) a[it--]=am[--lat]-'0';
	it=totl;
	while(lbt&&it>=1) b[it--]=bm[--lbt]-'0';
	
	for(int i=totl;i>=1;i--){
		if(a[i]+b[i]+flag>=10){
			c[i]=a[i]+b[i]+flag-10;
			flag=1;
		}else{
			c[i]=a[i]+b[i]+flag;
			if(flag!=0) flag--;
		}
	}
	
	if(c[1]>=10){
		c[1]=c[1]-10;
		c[0]=1;
		it=0;
	}else it=1;
	
	for(int i=1;i<=totl;i++) cout<<b[i];
	cout<<endl;
	for(int i=1;i<=totl;i++) cout<<a[i];
	cout<<endl;
	for(int i=it;i<=totl;i++) cout<<c[i];
	return 0;
}
