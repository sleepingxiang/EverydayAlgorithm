#include<iostream>
#include<string>
using namespace std;
struct Bitree
{
    string data;
    Bitree *lchild;
    Bitree *mchild;
    Bitree *rchild;
};

void D_(string[],int&,Bitree* &,Bitree* &);
void P(string[],int&,Bitree* &,Bitree* &);
void D(string[],int&,Bitree* &,Bitree* &);
void N_(string[],int&,Bitree* &,Bitree* &);
void Q(string[],int&,Bitree* &,Bitree* &);


void D_(string s[],int &index,Bitree* &head,Bitree* &p)
{
    Bitree *oldD_=p;
    //����������
    Bitree *newNode=new Bitree;
    newNode->data="D";
    newNode->lchild=NULL;
    newNode->mchild=NULL;
    newNode->rchild=NULL;
    p->lchild=newNode;
    p=newNode;
    D(s,index,head,p);
    p=oldD_;

    //����������
    Bitree *newNode2=new Bitree;
    newNode2->data="P";
    newNode2->lchild=NULL;
    newNode2->mchild=NULL;
    newNode2->rchild=NULL;
    p->rchild=newNode2;
    p=newNode2;
    P(s,index,head,p);
}

void D(string s[],int &index,Bitree* &head,Bitree* &p)
{
    if(s[index]=="int ")
        {
            cout<<s[index]<<"ƥ��ɹ���"<<endl;
            index++;
            Bitree *oldD=p;
            //����������
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1];
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;

            //����������
            Bitree *newNode2=new Bitree;
            newNode2->data="N_";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            N_(s,index,head,p);
            p=oldD;
            if(s[index]==";")
                {
                    cout<<s[index]<<"ƥ��ɹ���"<<endl;
                    Bitree *newNode3=new Bitree;
                    newNode3->data=s[index];
                    newNode3->lchild=NULL;
                    newNode3->mchild=NULL;
                    newNode3->rchild=NULL;
                    p->rchild=newNode3;
                }
        }
    else
        {
            //cout<<"E r r o r------"<<endl;
            return;
        }
}


void P(string s[],int &index,Bitree* &head,Bitree* &p)
{

    if(s[index]=="int")
        {
            D(s,index,head,p);
            P(s,index,head,p);
        }

   else
    {
        return;
    }

}

void N_(string s[],int &index,Bitree* &head,Bitree* &p)
{
    if(s[index]=="id")
        {
            cout<<s[index]<<"ƥ��ɹ���"<<endl;
            index++;
            //����������
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1];
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;

            //
            Bitree *newNode2=new Bitree;
            newNode2->data="Q";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->rchild=newNode2;
            p=newNode2;
            Q(s,index,head,p);
        }
}

void Q(string s[],int &index,Bitree* &head,Bitree* &p)
{
      if(s[index]==",")
        {
            cout<<s[index]<<"ƥ��ɹ���"<<endl;
            index++;
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1];
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            if(s[index]=="id")
                {
                    cout<<s[index]<<"ƥ��ɹ���"<<endl;
                    index++;
                    Bitree *newNode2=new Bitree;
                    newNode2->data=s[index-1];
                    newNode2->lchild=NULL;
                    newNode2->mchild=NULL;
                    newNode2->rchild=NULL;
                    p->mchild=newNode2;

                    //����������
                        Bitree *newNode3=new Bitree;
                        newNode3->data="Q";
                        newNode3->lchild=NULL;
                        newNode3->mchild=NULL;
                        newNode3->rchild=NULL;
                        p->rchild=newNode3;
                        p=newNode3;
                        Q(s,index,head,p);
                }
        }
    else
            return;

}


  //��һ�������в�α���
void Floor(Bitree *head)
{

    Bitree *Q[50];
    int Front=0;
    int Rear=0;
    //��Ԫ�ؽ���
    Q[Front++]=head;
    int layer=1;
    //int floor=6;//����
    while(Rear!=Front)
        {
            Bitree *p=Q[Rear++];

            if(p->lchild)
                {
                    Q[Front++]=p->lchild;
                }
            if(p->mchild)
                {
                    Q[Front++]=p->mchild;
                }
            if(p->rchild)
                {
                    Q[Front++]=p->rchild;
                }

            cout<<p->data<<" ";
            if(Rear==layer)
                {
                    cout<<endl;
                    layer=Front;
                    //floor--;
                }
        }


}


int main()
{
    string s[7]={"int ","id",",","id",",","id",";"};
    int index=0;
    Bitree *head=new Bitree;
    Bitree *p;
    head->data="D";
    head->lchild=NULL;
    head->mchild=NULL;
    head->rchild=NULL;
    p=head;
    D_(s,index,head,p);
    Floor(head);
}

