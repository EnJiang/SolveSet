
#include<cstring>
#include<iostream>
using namespace std;


/*
* Prim��MST
* �ķѾ���cost[][]����Ŵ�0��ʼ��0~n-1
* ������С��������Ȩֵ������-1��ʾԭͼ����ͨ
*/
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
int lowc[MAXN];
int cost[MAXN][MAXN];
int Prim(int n)//����0~n-1
{
	int ans = 0;
	memset(vis, false, sizeof(vis));
	vis[0] = true;
	for (int i = 1; i<n; i++)lowc[i] = cost[0][i];
	for (int i = 1; i<n; i++)
	{
		int minc = INF;
		int p = -1;
		for (int j = 0; j<n; j++)
			if (!vis[j] && minc>lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		if (minc == INF)return -1;//ԭͼ����ͨ
		ans += minc;
		vis[p] = true;
		for (int j = 0; j<n; j++)
			if (!vis[j] && lowc[j]>cost[p][j])
				lowc[j] = cost[p][j];
	}
	return ans;
}
