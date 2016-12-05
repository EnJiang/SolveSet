#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf = 0x3f3f3f3f;
int least_t;
const int maxn = 21;
const int maxk = 10;
char mp[maxn][maxn];//��ͼ
bool used[maxn][maxn];
int m, n;
int tx, ty;
int opti[maxn][maxn][maxk];//�洢��ǰ���Ž�
void dfs(int curx, int cury, int magic,bool wall, int t)
{
	if (used[curx][cury] || (t+abs(tx - curx)+abs(cury - ty)) > least_t)//��֦
	{
		return;
	}
	if (opti[curx][cury][magic] <= t)//��֦
	{
		return;
	}
	opti[curx][cury][magic] = t;
	if (mp[curx][cury] == 'T')//�����յ�
	{
		least_t = min(least_t, t);
	}
	if (mp[curx][cury] == 'x')//����ǽ
	{
		if (magic == 0||wall)//������ħ�������߲��ܶ��δ�ǽ
		{
			return;
		}
		magic--;
		wall = true;
	}
	else
	{
		wall = false;
	}
	used[curx][cury] = true;
	//��չ״̬
	if (curx > 0)
	{
		dfs(curx - 1, cury, magic,wall, t + 1);
	}
	if (curx < m - 1)
	{
		dfs(curx + 1, cury, magic,wall, t + 1);
	}
	if (cury > 0)
	{
		dfs(curx, cury - 1, magic,wall, t + 1);
	}
	if (cury < n - 1)
	{
		dfs(curx, cury + 1, magic,wall, t + 1);
	}
	used[curx][cury] = false;
}

int main()
{
	int tt;
	memset(used, 0, sizeof(used));
	while (cin >> tt)
	{
		while (tt--)
		{
			int mgc;
			memset(opti, inf, sizeof(opti));
			least_t = inf;
			cin >> m >> n >> mgc;
			int sx, sy;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> mp[i][j];
					if (mp[i][j] == 'S')
					{
						sx = i;
						sy = j;
					}
					if (mp[i][j] == 'T')
					{
						tx = i;
						ty = j;
					}
				}
			}

			dfs(sx, sy, mgc,false, 0);

			if (least_t == inf)//�����˵����
			{
				cout << -1 << endl;
			}
			else
			cout << least_t << endl;
		}
	}
}