#include<string>
#include<algorithm>
#include<iostream>
#include<cctype>

using namespace std;
int main()
{
	string line;
	while (cin>>line)
	{
		for (auto i = line.begin(); i != line.end(); i++)
		{
			*i = tolower(*i);//�����ַ�����Сд
		}
		int pos = line.find("bob");//����find��Ա����
		if (pos != string::npos)
		    cout << pos << endl;
		else
		{
			cout << -1 << endl;
		}
	}
}