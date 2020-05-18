#include<iostream>
using namespace std;

void Counting(int* &a,int n)
{
    //a数组的引用
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
                            //j可以整除i
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
                    cout<<i<<"号门是打开的"<<endl;
                }
            else if(a[i]%2==0)
                {
                    cout<<i<<"号门是关闭的"<<endl;
                }
        }
}

int main()
{
    Day03(24);
}
