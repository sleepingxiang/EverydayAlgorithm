#include<iostream>
using namespace std;
//�ȸ�������
//��һ���������ҳ�����ΪK�����������䣬ʹ��Щֵ���������


struct Object
{
    int data;
    int index;
};

//ð��������һ����������е�ֵ
Object* Sort(Object *a,int length)
{
    for(int i=0;i<length-1;i++)
        {
            for(int j=0;j<length-1-i;j++)
                {
                    if(a[j].data<a[j+1].data)
                        {
                            Object temp=a[j];
                            a[j]=a[j+1];
                            a[j+1]=temp;
                        }
                }
        }
        return a;
}


int nearBy(int index1,int index2,int k)
{
    if(index1>index2)
        {
            if(index1-index2<=k-1)
                {
                    //�غ�
                    return 1;
                }
            else
                return 0;
        }
    else
        {
            if(index2-index1<=k-1)
                {
                    return 1;
                }
            else
                {
                    return 0;
                }
        }
}
//�ж��Ƿ��ڵ㼯��
void IsIn(int a,int *b)
{

}


void lesson05(int *a,int length,int k)
{
    //�������������
    Object sum[length-(k-1)];
    for(int i=0;i<=length-k;i++)
        {
              sum[i].data=a[i]+a[i+1]+a[i+2];


            sum[i].index=i;
        }

        //�﷨�ϰ�
    Object* newSum=Sort(sum,length-(k-1));

    //���ڿ�ʼ����Object����
    int start=0;
    int ending=1;
    int total=3;
    int *select=new int;
    int select_num=0;
    bool found=false;
    while(total)
        {
            while(nearBy(newSum[start].index,newSum[ending].index,k))
                {
                    //���startָ��Ķ����endingָ��Ķ�����index�ص�
                    ending++;
                }

            if(ending-start>1)
                {
                    cout<<"ending="<<ending;

                    int zanding=newSum[start].data+newSum[ending].data;
                    for(int i=start+1;i<ending-1;i++)
                        {
                            for(int j=i+1;j<=ending-1;j++)
                                {
                                    if((!nearBy(newSum[i].index,newSum[j].index,k))&& (newSum[i].data+newSum[j].data>=zanding))
                                        {
                                            //�������û���ص� ��ֵ�����ݶ�
                                            start=i;
                                            ending=start+1;
                                            found=true;
                                            break;

                                        }

                                }

                        }
                    //û����
                    if(!found)
                        {
                            total--;
                            cout<<newSum[start].index<<" ";
                            start=ending;
                            ending++;
                        }
                }
            else
                {
                    total--;
                    /*
                    for(int l=0;l<k;l++)
                        {
                            select[select_num+l]=newSum[start].index+l;
                        }
                        */
                    cout<<newSum[start].index<<" ";
                    start=ending;
                    ending++;
                }
        }




}

int main()
{
    int a[11]={1,2,1,2,6,7,5,1,4,1,1};
    lesson05(a,11,3);
}
