#include<iostream>
#include<string>
using namespace std;

//�ú��������ж��ַ������͵ĵ��������ֵ���
int Print(string s)
{
    string keyword[10]={"int","main","void","string","while","if","cout"};

    //�ؼ��ֵ����
    for(int i=0;i<6;i++)
        {
            if(s==keyword[i])
                {
                    cout<<"["<<s<<","<<"�ؼ���"<<"]"<<endl;
                    return 1;
                }
        }
        return 0;




    //��ʶ�������


}


//�ʷ����������ɵ���
void Cifafenxiqi(string s)
{
    int i=0;

    //�������������ʾ�ؼ��ֱ�
    while(s[i]!='$')
        {
            if(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_')
                {
                    char *x=new char;
                    int numI=0;
                    x[numI]=s[i];
                    i++;
                    //�п����Ǳ�ʶ����Ҳ�п����ǹؼ���,�����Ҵ��㻻һ�ַ���
                    while(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_'|| s[i]>='0'&&s[i]<='9')
                        {

                           x[++numI]=s[i++];
                           //x.to_string();


                        }//whileѭ���������ñ�ʶ���Ѿ�����

                    string word=x;

                    if(!Print(word))
                        {
                            cout<<"["<<word<<","<<"��ʶ��"<<"]"<<endl;
                        }



                }
            else if(s[i]>='1'&&s[i]<='9')
                {
                    //����
                    char *x=new char;
                    int numI=0;
                    x[numI]=s[i];
                    i++; //һ���Ż�һ��
                    while(s[i]>='0'&&s[i]<='9')
                        {
                            x[++numI]=s[i++];
                        }

                    string word=x;
                    cout<<"["<<word<<","<<"����"<<"]"<<endl;


                }
            else if(s[i]=='{')
                {
                    cout<<"["<<s[i]<<","<<"�ָ���"<<"]"<<endl;
                    i++;
                }
            else if(s[i]=='}')
                {
                    cout<<"["<<s[i]<<","<<"�ָ���"<<"]"<<endl;
                    i++;
                }
            else if(s[i]=='(')
                {
                    cout<<"["<<s[i]<<","<<"�ָ���"<<"]"<<endl;
                    i++;
                }
            else if(s[i]==')')
                {
                    cout<<"["<<s[i]<<","<<"�ָ���"<<"]"<<endl;
                    i++;
                }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
                {
                    cout<<"["<<s[i]<<","<<"�����"<<"]"<<endl;
                    i++;
                }
            else
                {
                    //�ո�ע�͵������ַ���ֱ�Ӻ��Բ���
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
