#include<iostream>
using namespace std;
//����һ������ΪN�����飬����ֻ��һ�����ֳ����������Σ�����ľ�������ż����
//д��һ�������㷨�����ҳ��������


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
