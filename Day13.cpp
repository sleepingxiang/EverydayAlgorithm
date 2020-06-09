#include<iostream>
using namespace std;
//这个程序用来实现N皇后的递归操作
struct Stack
{
    int data[10];
    int top=-1;
};
//入栈操作
void Push(Stack &s,int data)
{
    s[++s.top]=data;
}
//出栈操作
int Pop(Stack &s)
{
    int x=s[s.top--];
    return x;
}
