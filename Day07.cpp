#include<iostream>
using namespace std;
//给定一个长度为N的数组，其中只有一个数字出现了奇数次，其余的均出现了偶数次
//写出一个最优算法，，找出这个数字


void position(int *a,int length)
{
    int x=0;
    for(int i=0;i<length;i++)
        {
            x=x^a[i];
        }
    cout<<x;
}

int main()
{
    //int a[11]={1,7,6,2,1,6,7,8,7,7,2};
    //position(a,11);
    int a=429467229665;
    cout<<a;
}
