#include<iostream>
using namespace std;

int huafen(int* &a,int low,int high)
{
    int temp=a[low];
    while(low<high)
        {
            while(low<high&&a[high]>temp)
                high--;
            a[low]=a[high];
            while(low<high&&a[low]<temp)
                low++;
            a[high]=a[low];
        }
        a[low]=temp;
        return low;

}

//�ҳ�A�����е���ֵ�������
void lesson(int *a)
{

    int mid=huafen(a,0,6);
    int start=0;
    int ending=6;
    int s=3;

    while(mid!=3)
        {
            if(mid<3)
                {
                    start=mid+1;
                    mid=huafen(a,start,ending);


                }
            else if(mid>s)
                {
                    ending=mid-1;
                    mid=huafen(a,start,ending);

                }
        }

    cout<<"�ҳ�������"<<a[mid];
}

int main()
{
    int *a=new int;
    a[0]=2;
    a[1]=4;
    a[2]=8;
    a[3]=7;
    a[4]=1;
    a[5]=6;
    a[6]=9;
    lesson(a);


}


