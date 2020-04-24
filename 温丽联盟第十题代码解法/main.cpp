#include<iostream>
#include<cstring>
using namespace std;
const double E=2.72;
//char a[100]={'2','5','6'};
//char b[100]={'3','2'};

typedef struct node{
	char a[10001];
	node(){memset(a,0,sizeof(a));return;}
	void operator * (const node &x)const{
		int m[101],n[101],r[101];
		memset(m,0,sizeof(m));
		memset(n,0,sizeof(n));
		memset(r,0,sizeof(r));
		for(int i=1;i<=strlen(a);i++)
			m[i]=a[strlen(a)-i]-'0';
		for(int i=1;i<=strlen(x.a);i++)
			n[i]=x.a[strlen(x.a)-i]-'0';
		
		int flag=0;
		for(int i=1;i<=strlen(a);i++){
			for(int j=1;j<=strlen(x.a);j++){
				int g=r[i+j-1]+m[i]*n[j];
				r[i+j-1]=g%10;
				flag=g/10;r[i+j]+=flag;
				flag=0;
			}
		}
		
		for(int i=1;i<=strlen(a)+strlen(x.a);i++)
			cout<<r[i];
		return;
	} 
	
};

void cross(char *x,char *y){
	int m[101],n[101],r[101];
	memset(m,0,sizeof(m));
	memset(n,0,sizeof(n));
	memset(r,0,sizeof(r));
	for(int i=1;i<=strlen(x);i++)
		m[i]=x[strlen(x)-i]-'0';
	for(int i=1;i<=strlen(y);i++)
		n[i]=y[strlen(y)-i]-'0';
	
	int flag=0;
	for(int i=1;i<=strlen(x);i++){
		for(int j=1;j<=strlen(y);j++){
			int g=r[i+j-1]+m[i]*n[j];
			r[i+j-1]=g%10;
			flag=g/10;r[i+j]+=flag;
			flag=0;
		}
	}
	
	for(int i=1;i<=strlen(x)+strlen(y);i++)
		cout<<r[i];
}

inline double convert(double x){  //保留两位小数转化器 
	x*=100;x-=(x-double(int(x)));
	return x/100;
}

double f(double x,int time,int tar){
	double tot1,tot2;
	tot1=tot2=1;
	for(int i=1;i<=int(x);i++){tot1*=E;tot1=convert(tot1);}
	for(int i=1;i<=int(x)+1;i++){tot2*=E;tot2=convert(tot2);} 
	double tot=(tot1+tot2)/2;
//	cout<<x<<" "<<time<<" "<<tot<<endl;
//	getchar();
	if(time==tar) return convert(tot-x-1);
	f(convert(tot-x-1),++time,tar);
}

int main(){
	node a,b;
	cin>>a.a>>b.a;
	a*b;
	return 0;
}
