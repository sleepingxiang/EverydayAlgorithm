#include<iostream>
#include<string>
using namespace std;
int Compare(string,string);
//最长公共前缀
void Day16(string s[4])
{
   int Min=99;
   int num=0;
   for(int i=0;i<3;i++)
    {
        num=Compare(s[i],s[i+1]);
        if(num<Min)
            {
                Min=num;
            }
    }

    string finalman=s[0];
    for(int i=0;i<Min;i++)
        {
            cout<<finalman[i];
        }



}

int Compare(string s1,string s2)
{
    int index=0;
    int Count=0;
    while(1)
        {
            if(s1[index]==s2[index])
                {
                    Count++;
                    index++;
                }
            else
                {
                    break;
                }
        }
    return Count;
}

int main()
{
    string s[4]={"bake","qual","cc","dnmb"};
    Day16(s);
}
