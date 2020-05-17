#include<iostream>
#include<string>
using namespace std;

//标识符的识别
void Identify(string s)
{
    int i=0;
    int num=0;
    while(s[i]!='$')
        {
            if(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_')
                {
                    //字母开头或标识符中包含这些字符
                    num++;
                }
            else if(s[i]>='0'&&s[i]<='9')
                {
                    if(num>0)
                        num++;
                    else
                        num=0;//数字为首字符的情况，跳过
                }
            else
                {
                    //空格等其他字符的情况
                    if(num>0)
                        {
                            while(num)
                                {
                                    cout<<s[i-num];
                                    num--;
                                }
                            cout<<endl;
                        }

                }
            i++;
        }

}

int main()
{
    string str="9_happy tik; tok_90}  $";
    Identify(str);
}
