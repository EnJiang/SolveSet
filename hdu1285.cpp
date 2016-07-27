#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int a[10000][2];
int b[600];
struct point{
	int x;
	int id;
};
bool cmp(const point & a, const point & b)   //����
{
	if(a.x>b.x)
	{
	    return true;
    }
    if(a.x == b.x)
    {
        return a.id>b.id;
    }
    return false;
}                              
int main()
{
	cin>>n>>m;
	point p[100];
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<2; j++)
			{
				cin>>a[i][j];
			}
	}
	memset(b, 0, sizeof(b));
	for(int i=0; i<m; i++)    //�ѵ÷ֺ�id��team������������� 
	{
		b[a[i][0]]++;
	}
	
	for(int i=1; i<=n; i++)   //�ѵ÷ֺ�id�ֿ����Ա����� 
	{
		p[i].x = b[i];
		p[i].id = i;
	}
	
	sort(p+1, p+n+1, cmp);   //��p�ĵ�һ������ 
	
	for(int i=1; i<=n; i++)     
		cout<<p[i].id<<" ";
	
	cout<<endl;
	return 0;
}
