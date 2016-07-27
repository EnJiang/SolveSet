#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 6;
bool cooked[maxn][maxn];
int bar[maxn][maxn];
const int inf = 0x3f3f3f3f;
int n, min_t;
//DFS�� ���Ѿ����ڵĴ�����չ
void dfs(int t)
{
	if (t >= min_t)
	{
		return;
	}
	bool done = true;
	vector<bool> cooked_row(n, false);//�����һ�Ż�����һ��
	vector<bool> cooked_col(n, false);
	//�������е�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//ÿһ��û��ĵ㶼���������ڵ��к��ſɲ�������
			if (bar[i][j] && !cooked[i][j])
			{
				done = false;
				bool row = true, col = true;
				for (int k = 0; k < n; k++)
				{
					if (cooked[i][k])
					{
						row = false;
						break;
					}
					if (cooked[k][j])
					{
						col = false;
						break;
					}
				}
				//�����һ�ſ����գ��Ǿ����첢��չ״̬
				if (row&&!cooked_row[i])
				{
					cooked_row[i] = true;
					for (int k = 0; k < n; k++)
					{
						if (bar[i][k])
						{
							cooked[i][k] = true;
						}
					}
					dfs(t + 1);
					for (int k = 0; k < n; k++)
					{
						cooked[i][k] = false;
					}
				}
				//�����һ�п����գ��Ǿ�����Ȼ����չ״̬
				if (col && !cooked_col[j])
				{
					cooked_col[j] = true;
					for (int k = 0; k < n; k++)
					{
						if (bar[k][j])
						{
							cooked[k][j] = true;
						}
					}
					dfs(t + 1);
					for (int k = 0; k < n; k++)
					{
						cooked[k][j] = false;
					}
				}
			}
		}
	}
	if (done)
	{
		min_t = min(min_t, t);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int tt;
	memset(cooked, 0, sizeof(cooked));
	while (cin >> tt)
	{
		while (tt--)
		{
			min_t = inf;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> bar[i][j];
				}
			}
			dfs(0);//��0�ο�ʼ
			cout << min_t << endl;
		}
	}
}