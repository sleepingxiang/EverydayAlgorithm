#include<iostream>
using namespace std;
//÷±Ω”≤Â»Î≈≈–Ú

void lesson04(int* a,int length)
{
    for(int i=2;i<length;i++)
        {
            if(a[i]<a[i-1])
                {
                    int temp=a[i];
                    for(int j=i;j>0;j--)
                        {
                            if(temp>a[j-1])
                                {
                                    a[j]=temp;
                                    break;
                                }
                            else
                                {
                                    a[j]=a[j-1];

                                }
                        }
                }
        }

    for(int i=0;i<length;i++)
        {
            cout<<a[i]<<" ";
        }

}


int main()
{
    int b[8]={0,89,45,68,29,34,17,92};
    lesson04(b,8);
}
