#include<iostream>
using namespace std;

//����Ŀ��Ϊ���������ҳ���������Ӻ�Ϊ0��Ԫ��

//���η����Ƚ��������ֽ�ΪCn-3������0


//���㷨���ڽ����N������ȡ�����������н��
void Sieve(int arr[],int a[],int length,int result[],int start,int Count)
{
    if(Count!=3)
        {
            for(int i=start;i<length;i++)
                {

                    result[Count]=a[i];
                    Sieve(arr,a,6,result,i+1,Count+1);
                }

        }
    else
        {
            int zanding=0;
            for(int j=0;j<3;j++)
            {
                zanding+=arr[result[j]];
            }
            if(zanding==0)
                {
                    for(int k=0;k<3;k++)
                        {
                            cout<<"["<<arr[result[k]]<<" ";
                            cout<<"]";
                        }
                        cout<<endl;
                }
           zanding=0;

            return;
        }
}


void SumOfThree(int a[],int length)
{
    int index[6]={0,0,0,0,0,0};
    int result[3]={0,0,0};
    for(int i=0;i<length;i++)
        {
            index[i]=i;
        }
    Sieve(a,index,length,result,0,0);
}


int main()
{
    int a[6]={-1,0,1,2,-1,4};
    //Sieve(a,6,result,0,0);
    SumOfThree(a,6);
}
