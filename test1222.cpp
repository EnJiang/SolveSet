#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd_extend(int a,int b,int &x,int &y)//ŷ������㷨��չ��ʽ
{
    if(!b){
        x=1;
        y=0;
    return a;}
    int g=gcd_extend(b,a%b,x,y);
    int t=x-(a/b)*y;
    x=y;
    y=t;
    return g;
}
/*
void solver(int a,int b,int n)//�ⷽ��
{
    int x,y;
    int d=gcd_extend(a,n,x,y);
    if(b%d==0)
    {
        int x1=x*(b/d)%n;
        for(int i=0;i<d;i++)
        cout<<(x1+i*(n/d))%n<<endl;
    }
    else
    cout<<"�޽�"<<endl;
}
*/
void solver(int a,int b,int n)//�ⷽ��
{
    int x,y;
    int d=gcd_extend(a,n,x,y);
    if(b%d==0)
    {
        int x1=x*(b/d)%n;
        for(int i=0;i<d;i++)
          {
              int t=(x1+i*(n/d))%n;//���ڸ��������壬��ô������Ҫ�ж������
              if(t<0)
              {
                  t=(t+n)%n;
              }
              cout<<t<<endl;
          }
    }
    else
    cout<<"�޽�"<<endl;
}
int main()
{
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        solver(a,b,n);
    }
    return 0;
}

/*
����ģ���Է��̵�ģ�棬�Լ�д�ģ�����

�������ݣ�
14 30 100
10 20 30
10 35 62

95 45
2 5 8 11 14 17 20 23 26 29
�޽�
*/
