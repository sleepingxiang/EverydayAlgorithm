#include<iostream>
using namespace std;

void Counting(int* &a,int n)
{
    //a���������
    for(int i=0;i<=n;i++)
        {
            a[i]=0;
        }
    for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
                {
                    if(j%i==0)
                        {
                            //j��������i
                            a[j]++;
                        }
                }
        }
}

void Day03(int n)
{
    int *a=new int;
    Counting(a,n);

    for(int i=1;i<=n;i++)
        {
            if(a[i]%2==1)
                {
                    cout<<i<<"�����Ǵ򿪵�"<<endl;
                }
            else if(a[i]%2==0)
                {
                    cout<<i<<"�����ǹرյ�"<<endl;
                }
        }
}

int main()
{
    Day03(24);
}
