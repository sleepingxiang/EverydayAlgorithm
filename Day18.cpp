#include<iostream>
#include<math.h>
using namespace std;

//���⣬����ʵ��������ת
void lesson18(int a)
{
    if(a<0)
        {
            cout<<"-";
        }
   int yu=0;
   a=fabs(a);
    while(a!=0)
        {
            yu=a%10;
            a=a/10;
            if(yu!=0)
                cout<<yu;

        }

}

int main()
{
    lesson18(-120);
}
