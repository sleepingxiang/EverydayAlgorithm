#include<iostream>
#include<string>
using namespace std;

//该函数用于判断字符串类型的单词是哪种单词
int Print(string s)
{
    string keyword[10]={"int","main","void","string","while","if","cout"};

    //关键字的情况
    for(int i=0;i<6;i++)
        {
            if(s==keyword[i])
                {
                    cout<<"["<<s<<","<<"关键字"<<"]"<<endl;
                    return 1;
                }
        }
        return 0;




    //标识符的情况


}


//词法分析，生成单词
void Cifafenxiqi(string s)
{
    int i=0;

    //这个数组用来表示关键字表
    while(s[i]!='$')
        {
            if(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_')
                {
                    char *x=new char;
                    int numI=0;
                    x[numI]=s[i];
                    i++;
                    //有可能是标识符，也有可能是关键字,这里我打算换一种方法
                    while(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_'|| s[i]>='0'&&s[i]<='9')
                        {

                           x[++numI]=s[i++];
                           //x.to_string();


                        }//while循环结束，该标识符已经结束

                    string word=x;

                    if(!Print(word))
                        {
                            cout<<"["<<word<<","<<"标识符"<<"]"<<endl;
                        }



                }
            else if(s[i]>='1'&&s[i]<='9')
                {
                    //常数
                    char *x=new char;
                    int numI=0;
                    x[numI]=s[i];
                    i++; //一会优化一下
                    while(s[i]>='0'&&s[i]<='9')
                        {
                            x[++numI]=s[i++];
                        }

                    string word=x;
                    cout<<"["<<word<<","<<"常数"<<"]"<<endl;


                }
            else if(s[i]=='{')
                {
                    cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    i++;
                }
            else if(s[i]=='}')
                {
                    cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    i++;
                }
            else if(s[i]=='(')
                {
                    cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    i++;
                }
            else if(s[i]==')')
                {
                    cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    i++;
                }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
                {
                    cout<<"["<<s[i]<<","<<"运算符"<<"]"<<endl;
                    i++;
                }
            else
                {
                    //空格注释等垃圾字符，直接忽略不计
                    i++;

                }
        }
}



int main()
{
    string str="int main()\n{\n   int a=bisic+5680;\n   if(a=3)\n}$";
    cout<<str<<endl;
    Cifafenxiqi(str);
}
