#include<iostream>
#include<string>
using namespace std;

//����ƥ��

bool Pipei(char a,char b)
{
    if(a=='('&&b==')')
        {
            return true;
        }
    else
            return false;
}

void lesson11(string s)
{
    int Max=0;
    int i=0;
    char Stack[10];
    int top=-1;
    while(s[i]!='$')
        {
            if(s[i]=='(')
                Stack[++top]=s[i++];
            else if(s[i]==')')
                {
                    if(Pipei(Stack[top],s[i]))
                        {
                            //��ջ
                            char xx=Stack[top--];
                            Max+=2;
                            i++;
                        }
                    else
                        {
                            Stack[++top]=s[i++];
                        }
                }
        }
        cout<<"���Ч���ų���Ϊ"<<Max<<endl;
}

int main()
{
    string s=")()())$";
    lesson11(s);
}
