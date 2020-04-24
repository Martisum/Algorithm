#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxm=41;
int n,m,l[1001],a,b,c,d,e;
int f[maxm][maxm][maxm][maxm];

int main(){
	freopen("win.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	for(int i=1;i<=m;i++){
		cin>>e;
		if(e==1) a++;
		else if(e==2) b++;
		else if(e==3) c++;
		else if(e==4) d++;
	}
	
	f[0][0][0][0]=l[1];
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				for(int s=0;s<=d;s++){
//					if(f[i][j][k][s]){
						f[i+1][j][k][s]=max(f[i+1][j][k][s],f[i][j][k][s]+l[(i+1)+j*2+k*3+s*4+1]);
						f[i][j+1][k][s]=max(f[i][j+1][k][s],f[i][j][k][s]+l[i+(j+1)*2+k*3+s*4+1]);
						f[i][j][k+1][s]=max(f[i][j][k+1][s],f[i][j][k][s]+l[i+j*2+(k+1)*3+s*4+1]);
						f[i][j][k][s+1]=max(f[i][j][k][s+1],f[i][j][k][s]+l[i+j*2+k*3+(s+1)*4+1]);
//					}
				}
			}
		}
	}
	
	cout<<f[a][b][c][d]<<endl;
	return 0;
}

