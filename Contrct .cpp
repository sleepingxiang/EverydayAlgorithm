#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string CutString(string);
//外观数列
//假定初始数字是3
void test01(string &s,int n)
{
	if(n==1)
	{
		cout << s;
	}
	if(n>1)
	{
		s = CutString(s);
		test01(s, n - 1);
	}
}

string CutString(string s)
{
	string newS = "";
	int counter = 1;
	for (int i = 0; i < s.length(); i++)
	{
		
		if(s[i]!=s[i+1])
		{
			newS = newS+ to_string(counter) + s[i];
			counter = 1;
		}
		else
		{
			counter++;
		}
	}
	return newS;
}

int main()
{
	string str = "3";
	test01(str, 5);
}