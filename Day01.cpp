#include<iostream>
#include<string>
using namespace std;

//��ʶ����ʶ��
void Identify(string s)
{
    int i=0;
    int num=0;
    while(s[i]!='$')
        {
            if(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_')
                {
                    //��ĸ��ͷ���ʶ���а�����Щ�ַ�
                    num++;
                }
            else if(s[i]>='0'&&s[i]<='9')
                {
                    if(num>0)
                        num++;
                    else
                        num=0;//����Ϊ���ַ������������
                }
            else
                {
                    //�ո�������ַ������
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
