#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=2019;
char ta[maxm],tb[maxm];
int a[maxm],b[maxm],c[maxm],e[maxm][maxm];
int lena,lenb,lenc,flag;

int main(){
	freopen("gin.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>ta>>tb;
	lena=strlen(ta);lenb=strlen(tb);
	lenc=max(lena,lenb);
	for(int i=0;i<=lenc-1;i++){
		a[i+1]=ta[i]-48;
		b[i+1]=tb[i]-48;
		if(a[i+1]==-48) a[i+1]=0;
		if(b[i+1]==-48) b[i+1]=0;
	}
	
	int high=0,wide=0;
	for(int i=lena,p=1;i>=1;i--,p++){
		for(int j=lenb,q=p;j>=1;j--,q++){
			e[p][q]=a[i]*b[j];
			if(e[p][q]>=10){
				int t=e[p][q]+flag;
				e[p][q]=t%10;flag=t/10;
				if(j==1){
					e[p][++q]=flag;
					flag=0;
					wide=max(wide,q);
				}
				continue;
			}
			wide=max(wide,q);
		}
		high=p;
	}flag=0;
	
//	cout<<high<<" "<<wide<<endl;
//	for(int i=1;i<=22;i++){
//		for(int j=1;j<=33;j++){
//			cout<<e[i][j]<<" ";
//		}cout<<endl;
//	}

//for(int i=1;i<=wide;i++)
//		for(int j=1;j<=high;j++)
//			c[i]+=e[j][i];
//
//for(int i=1;i<=wide;i++)
//	cout<<c[i]<<" ";
	
	int f=1;
	for(int i=1;i<=wide;i++){
		for(int j=1;j<=high;j++)
			c[i]+=e[j][i];
		if(c[i]+flag>=10){
			int t=c[i]+flag;
			flag=t/10;c[i]=t%10;
			if(i==wide){c[0]=flag;f=0;}	
			continue;
		}
		c[i]+=flag;
		flag=0;
	}
	
	for(int i=1;i<=wide>>1;i++) 
		swap(c[i],c[wide-i+1]);
	for(f;f<=wide;f++)
		cout<<c[f];
	return 0;
}

