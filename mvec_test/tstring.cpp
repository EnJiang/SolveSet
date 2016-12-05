

//test.cpp

/*
��Ŀ2���ַ����ࣨ����1��װC-�ַ��������߷���2��ʹ�ô�������־������int num�����ݳ�Ա��¼�ַ������ȣ���
*/


//String.cpp
//String.h
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class String
{
public:
	String(const char *str = NULL)//ͨ�ù���
    {
		if(!str)
		{
			len = 0;
			p = new char [1];
			*p = '\0';
		}
		else
    	{
			len = strlen(str);
      		p = new char [len+1];
      		strcpy(p,str);
		}
    }
	String(const String &other)//��������
    {
    	len = other.len;
      	p = new char [len+1];
      	strcpy(p,other.p);
    }
	~ String()//��������
  	{
      	delete[] p;
		len = 0;
    }
	int getLen() const //��ȡ����
    {
		return len;
	}
	inline const char* cStr() const//��ȡC�ַ���
	{
		return p;
	}
	String subStr(int start,int end)//���start��end��������
	{
		String t;
		if(start < 0||end > len)
			return t;
		t.len = end - start;
		t.p = new char [len + 1];
		strncpy(t.p,p+start,t.len);
		return t;
	}
	void repeat(int times)//�ظ�string����
	{
		while(times--)
		{
			*this = *this + *this;
		}
		len = len * times;
	}
	void print() const //��ӡC�ַ���
  	{
	    printf("%s",cStr());
	}
	void resize(int size)//�����趨���������sizeС�ڵ�ǰ��������ض�size֮����ַ�
	{
		if (size <= 0)
			return;
		len = size;
		char *t;
		t = new char [size+1];
		strncpy(t,p,len);
		delete[] p;
		p = t;
		len = size;
	}
	void clear()//��string��0���
	{
		memset(p,0,len*sizeof(char)+1);
	}

	bool operator ==(const String &other)//���������==
    {
    	if(len!=other.len)
          	return false;
      	else
      		if(strcmp(p,other.p)==0)
				return true;
		return false;
    }
	String & operator =(const String &other)//���������=
	{
    	if (this == &other)
			return *this;
		delete []p;
		len = other.len;
		p = new char[len + 1];
		strcpy(p, other.cStr());
		return *this;
    }
	String operator +(const String &other)//���������+
    {
    	String s;
		s.len = len + other.getLen();
		s.p = new char[s.len + 1];
		strcpy(s.p, p);
		strcat(s.p, other.p);
		return s;
    }
	bool operator >(const String &other)//���������>  <�Լ�<= >= ͬ��
	{
		if(strcmp(p,other.p)>0)
				return true;
		else
			return false;

	}
private:
	int len;//  �ַ�������
	char *p;//  �ַ����׵�ַ
};
int main()
{
	String t1("Hello");
	t1.print();
	String t2("World");
	t2.print();
	String t3(t1);
	t3.print();
	String t4;
	t4 = t1+t2;
	t4.print();
	if(t1>t2)
		printf("t1>t2\n");
	else
		printf("t1<=t2\n");
	if(t3==t1)
		printf("t1==t2\n");
	else
		printf("t1!=t2\n");
}
