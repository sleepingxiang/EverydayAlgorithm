#include<iostream>
using namespace std;
//ʢ���ˮ������
int GetMin(int a,int b)
{
   return (a>b)?b:a;
}

void lesson17(int a[],int length)
{
    int V=(length-1-1)*GetMin(a[1],a[length-1]);
    int maxV=V;
    int start=1;
    int ending=length-1;
    //V1��ȥ����ߵ����,V2��ȥ���ұߵ����,V3���ݶ��Ľ�С���
    int V1=0;
    int V2=0;
    int V3=0;
    while(start<ending)
        {
             V1=(ending-(start+1))*GetMin(a[start+1],a[ending]);
             V2=((ending-1)-start)*GetMin(a[start],a[ending-1]);
             if(V1<V2)
                {
                    start++;
                    V3=V2;
                }
             else
                {
                    ending--;
                    V3=V1;
                }

            if(V3>maxV)
                    maxV=V3;

        }
        cout<<maxV;


}


int main()
{
    int a[10]={0,1,8,6,2,5,4,8,3,9};
    lesson17(a,10);

}
