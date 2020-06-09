#include<iostream>
#include<string>
using namespace std;

//k个一组链表翻转

struct Node
{
    int data;
    Node *next;
};


//先建立一个带头节点的链表

void CreateList(Node* &head)
{
    Node *s=new Node;
    cout<<"请输入结点值"<<endl;
    cin>>s->data;
    s->next=NULL;
    head->next=s;
    Node *p=s;
    while(p->data!=5)
        {
            Node *s=new Node;
            cout<<"请输入结点值"<<endl;
            cin>>s->data;
            s->next=NULL;
            p->next=s;
            p=s;
        }

}

void Print(Node *head)
{
    while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
}


void lesson12(Node* &head,int k,int length)
{
    int duan=length/k;
    Node *start=NULL;
    Node *ending=head;
    Node *p=head->next;
    Node *q=p;
    while(duan)
        {
            duan--;
            for(int i=k;i>1;i--)
                {
                    q=q->next;
                }
            for(int j=0;j<k-1;j++)
                {
                    start=p->next;
                    p->next=q->next;
                    q->next=p;
                    p=start;
                }
            ending->next=q;
            for(int m=0;m<k-1;m++)
                {
                    p=p->next;
                }
            ending=p;
            p=p->next;
            q=p;
            start=NULL;
        }

}


int main()
{
    Node *head=new Node;
    head->data=9999;
    head->next=NULL;
    CreateList(head);
    Print(head);
    cout<<endl<<endl;
    lesson12(head,3,5);
    Print(head);
}
