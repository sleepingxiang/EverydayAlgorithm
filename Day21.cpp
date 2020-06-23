#include<iostream>
using namespace std;
void Day21(int a[],int length,int val)
{
    int Count=0;
    for(int i=0;i<length;i++)
        {
            if(a[i]==val)
                    Count++;
            else
                    a[i-Count]=a[i];
        }
        for(int i=0;i<length-Count;i++)
            {
                cout<<a[i]<<" ";
            }
}

int main()
{
    int a[8]={0,1,2,2,3,0,4,2};
    Day21(a,8,2);
}
