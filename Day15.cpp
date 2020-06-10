#include<iostream>
#include<string>
using namespace std;

bool IsHuiWen(string s,int start,int last)
{
    for(int i=start,j=last;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                    return false;
        }
    return true;
}


void Day15(string s,int length)
{
    int son=1;
    int Max_son=0;
    for(int i=0;i<length-1;i++)
        {
            for(int j=i+1;j<length;j++)
                {
                    if(IsHuiWen(s,i,j))
                        son=j-i+1;
                    else
                        {
                            if(son>Max_son)
                                {
                                    Max_son=son;
                                    son=1;
                                }
                        }
                }
        }
        cout<<"Max_son="<<Max_son;

}






int main()
{
    string s="abcdcba";
    Day15(s,7);
}
