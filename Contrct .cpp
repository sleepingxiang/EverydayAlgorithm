#include<iostream>
#include<string>
#include<math.h>
using namespace std;

//���������ظ�Ԫ��

int test01(int a[],int length,int x)
{
	for(int i=0;i<length;i++)
	{
		if(x<a[i])
		{
			return i;
		}
		else if(x==a[i])
		{
			return i;
		}
	}
	return length;
}


int main()
{
	int a[4] = { 1,3,5,6 };
	cout << test01(a, 4, 7);

}