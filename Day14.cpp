#include<iostream>
#include<string>
using namespace std;

void Day15(string,int);

void Day15(string s,int length)
{
    int start=0;
    int Max_son=1;
    int son=1;
    for(int i=1;i<length;i++)
        {
            for(int j=start;j<i;j++)
                {

                    if(s[j]==s[i])
                        {
                            if(son>=Max_son)
                                {
                                    Max_son=son;
                                    son=0;
                                }
                            start=i;
                            break;
                        }
                }
                son++;

        }
        cout<<Max_son<<endl;
}

int main()
{
    string s="abcabcdgg";
    Day15(s,9);
}
