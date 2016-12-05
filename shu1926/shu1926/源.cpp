#include<iostream>
#include<string>
#include<vector>
using namespace std;
//����ʵ�����ϸ���dfs
bool dfs(string &s, bool inserted, int low, int high)
{
	while (low < high)
	{
		if (s[low] != s[high])//���Ϸ������
		{
			if (inserted)//�ж��Ƿ��Ѿ�����
			{
				return false;
			}
			else
			{
				if (dfs(s, true, low + 1, high) || dfs(s, true, low, high - 1))//����һ���ַ�������һ���ַ��ǵȼ۵�
				{
					return true;
				}
				else
					return false;
			}
		}
		low++;
		high--;
	}
	return true;

}
int main()
{
	int t;
	string line;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> line;
			if (dfs(line, false, 0, line.size() - 1))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}