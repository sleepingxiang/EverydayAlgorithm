#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

//��������
void test01(int a[])
{
	//Ҫ�����������飬��ֵ���
	//�ö�̬�滮��
	int b[9];
	b[0] = a[0];
	int MaxNum = a[0];
	for(int i=1;i<9;i++)
	{
		b[i] = max(b[i - 1]+a[i], a[i]);
		if(b[i]>=MaxNum)
		{
			MaxNum = b[i];
		}
	}
	cout << MaxNum;
}



int main()
{
	int a[9] = { -2,1,-3,4,-1,2,1,-5,4 };
	test01(a);
}