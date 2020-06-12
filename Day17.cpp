#include<iostream>
using namespace std;
//盛最多水的容器
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
    //V1是去掉左边的体积,V2是去掉右边的体积,V3是暂定的较小体积
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
