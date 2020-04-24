#include <iostream>
 
using namespace std;
bool map[9][9];
int c[9]; //随便命名四种颜色
int ans = 0, N;
//依次枚举每个节点，来试与前面的节点是否有重合的，没有就下一层
void dfs(int n)
{
	int i, j;
	if(n > N) {ans++; return;}
	for(j = 1; j <= 4; j++) //依次枚举4种颜色
	{
		for(i = 1; i < n; i++){
			if(map[i][n] && c[i] == j){
				break;
			}
		}
		 //判断与n是否有链接并且颜色有无重合
		if(i == n) //没有重合，拓展下一节点
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

