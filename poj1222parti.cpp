#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 1e2+5;
int equ, var;///equ������ var������
int a[MAXN][MAXN];///�������
int x[MAXN];///�����Ŀ
bool free_x[MAXN];///�ж��ǲ������ɱ�Ԫ
int free_num;///���ɱ�Ԫ�ĸ���
inline int GCD(int m, int n)
{
    if(n == 0)
        return m;
    return GCD(n, m%n);
}
inline int LCM(int a, int b)
{
    return a/GCD(a,b)*b;
}

int Gauss()
{
    int Max_r;///��ǰ�о���ֵ���Ĵ��ڵ���
    ///col������ǰ����
    int row = 0;
    int free_x_num;
    int free_index;
    for(int col=0; row<equ&&col<var; row++,col++)
    {
        Max_r = row;
        for(int i=row+1; i<equ; i++)
            if(abs(a[i][col]) > abs(a[Max_r][col]))
                Max_r = i;

        if(Max_r != row)
            for(int i=0; i<var+1; i++)
                swap(a[row][i], a[Max_r][i]);

        if(a[row][col] == 0)
        {
            printf("debug\n");
            row--;
            continue;
        }
        for(int i=row+1; i<equ; i++)
        {
            if(a[i][col])
            {
                for(int j=col; j<var+1; j++)
                    a[i][j] ^= a[row][j];
            }
        }
    }
    for(int i=row; i<equ; i++)
        if(a[i][var])
            return -1;///�޽�

    for(int i=var-1; i>=0; i--)
    {
        int tmp = a[i][var];
        for(int j=i+1; j<var; j++)
            if (a[i][j])
                tmp ^= a[i][j]*x[j];
        if (tmp%a[i][i])
            return -2; /// ˵���и������⣬����������.
        x[i] = tmp/a[i][i];
    }
    return 0;///Ψһ��
}
int main()
{
    int T;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        memset(a, 0, sizeof(a));
        memset(x, 0, sizeof(x));
        equ =  var = 30;
        for(int i=0; i<var; i++)
        {
            int ta = i%6, tb = i/6;
            a[i][i] = 1;
            if(ta > 0)
                a[i][i-1] = 1;
            if(ta < 5)
                a[i][i+1] = 1;
            if(tb > 0)
                a[i][i-6] = 1;
            if(tb < 5)
                a[i][i+6] = 1;
        }


        for(int i=0; i<equ; i++)
            cin>>a[i][var];

        int k = Gauss();
        printf("PUZZLE #%d\n",cas);
        for(int i=0; i<var; i++)
        {
            if(i%6 == 5)
                cout<<x[i]<<endl;
            else
                cout<<x[i]<<" ";
        }
    }
    return 0;
}
