#include <iostream>
 
using namespace std;
bool map[9][9];
int c[9]; //�������������ɫ
int ans = 0, N;
//����ö��ÿ���ڵ㣬������ǰ��Ľڵ��Ƿ����غϵģ�û�о���һ��
void dfs(int n)
{
	int i, j;
	if(n > N) {ans++; return;}
	for(j = 1; j <= 4; j++) //����ö��4����ɫ
	{
		for(i = 1; i < n; i++){
			if(map[i][n] && c[i] == j){
				break;
			}
		}
		 //�ж���n�Ƿ������Ӳ�����ɫ�����غ�
		if(i == n) //û���غϣ���չ��һ�ڵ�
		{
			c[n] = j;
			dfs(n+1);
			c[n] = 0;
		}
	}
}
int main()
{
	freopen("sin.txt","r",stdin);
	cin >> N;
	int i, j;
	for(i = 1; i <= N; i++) for(j = 1; j <= N; j++) cin >> map[i][j];
	dfs(1);
	cout << ans;
	return 0;
}

