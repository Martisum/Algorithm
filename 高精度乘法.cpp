#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

const int maxm=1001;
char am[maxm],bm[maxm];
int a[maxm],b[maxm],c[maxm];
int la,lb,totl,flag,lat,lbt;

int e[maxm][maxm],h,s,ts; 

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
	
	
	h=1;s=la+lb;ts=s;
	for(int i=totl;i>=totl-lb;i--){
		for(int j=totl;j>=totl-la;j--){
			if(a[j]*b[i]+flag>=10){
				e[h][ts]=(a[j]*b[i]+flag)%10;
				flag=(a[j]*b[i]+flag)/10;
			}else{
				e[h][ts]=a[j]*b[i];
				if(flag!=0) flag=0;
			}
			ts--;
		}
		s--;
		ts=s;
		h--;
	}

	for(int i=1;i<=totl;i++) cout<<a[i];
	cout<<endl;
	for(int i=1;i<=totl;i++) cout<<b[i];
	cout<<endl;
	for(int i=it;i<=totl;i++) cout<<c[i];
	return 0;
}
