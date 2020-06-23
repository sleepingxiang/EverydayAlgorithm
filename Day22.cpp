#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void CreateList(Node* &head)
{
    Node *s=new Node;
    cout<<"输入结点的值"<<endl;
    cin>>s->data;
    s->next=NULL;
    Node *p;
    head->next=s;
    p=s;
    while(p->data!=0)
        {
            Node *s=new Node;
            cout<<"输入结点的值"<<endl;
            cin>>s->data;
            s->next=NULL;
            p->next=s;
            p=s;
        }
        delete s;

}


void Print(Node *head)
{
    while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
}


void Day22(Node* &head,int k)
{
    Node *p,*q;
    p=head->next;
    q=p;
    for(int i=k;i>0;i--)
        {
            q=q->next;
        }
    while(q->next!=NULL)
        {
            q=q->next;
            p=p->next;
        }
        //然后删去p后面哪一个
        Node *haha=p->next;
        p->next=haha->next;
        delete haha;
}


int main()
{
    Node *head=new Node;
    head->data=9999;
    head->next=NULL;
    CreateList(head);
   // Day22(head,2);
    Print(head);
}
