#include<iostream>
using namespace std;
//�����������ʵ��N�ʺ�ĵݹ����
struct Stack
{
    int data[10];
    int top=-1;
};
//��ջ����
void Push(Stack &s,int data)
{
    s[++s.top]=data;
}
//��ջ����
int Pop(Stack &s)
{
    int x=s[s.top--];
    return x;
}
