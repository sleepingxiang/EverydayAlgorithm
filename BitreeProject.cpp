#include<iostream>
#define maxsize 20
using namespace std;
int MaxHeight=0;
struct Bitree
{
    int data;
    Bitree *lchild;
    Bitree *rchild;
};

void CreateZY(Bitree* &head)
{
    Bitree *l=new Bitree;
    cout<<"请输入左孩子数据:"<<endl;
    cin>>l->data;
    l->lchild=NULL;
    l->rchild=NULL;
    head->lchild=l;

    Bitree *r=new Bitree;
    cout<<"请输入右孩子数据:"<<endl;
    cin>>r->data;
    r->lchild=NULL;
    r->rchild=NULL;
    head->rchild=r;
}
void CreateZ(Bitree* &head)
{
    Bitree *l=new Bitree;
    cout<<"请输入左孩子数据:"<<endl;
    cin>>l->data;
    l->lchild=NULL;
    l->rchild=NULL;
    head->lchild=l;

    head->rchild=NULL;
}
void CreateY(Bitree* &head)
{
    head->lchild=NULL;

    Bitree *r=new Bitree;
    cout<<"请输入右孩子数据:"<<endl;
    cin>>r->data;
    r->lchild=NULL;
    r->rchild=NULL;
    head->rchild=r;
}
//先序遍历
void PreOrder(Bitree* &head)
{
    if(head!=NULL)
        {
            cout<<head->data<<" ";
            PreOrder(head->lchild);
            PreOrder(head->rchild);
        }
}
//中序遍历
void InOrder(Bitree* &head)
{
    if(head!=NULL)
        {
            InOrder(head->lchild);
            cout<<head->data<<" ";
            InOrder(head->rchild);
        }
}
void lesson5(Bitree* &head)
{
    int Front=-1;
    int Rear=-1;
    Bitree Q[20];
    int level=0; //用来记录树的层数
    int last=0;//用来记录树该层中最右节点
    Bitree p=*head;
    Q[++Rear]=p;
    while(Front<Rear)
        {
            p=Q[++Front]; //出队
            if(p.lchild!=NULL)
                {
                    Q[++Rear]=*p.lchild;
                }
            if(p.rchild!=NULL)
                {
                    Q[++Rear]=*p.rchild;
                }
            if(Front==last)
                {
                    level++;
                    last=Rear;
                }
        }
        cout<<"一共有"<<level<<"层";
}

Bitree* lesson6(int a[],int b[],int l1,int h1,int l2,int h2)
{
    Bitree *p=new Bitree;
    p->data=a[l1];
    int llen=0;
    int rlen=0;
    int i=0;
    for(i=l2;b[i]!=p->data;i++);
    llen=i-l2;
    rlen=h2-i;
    if(llen)
        {
            p->lchild=lesson6(a,b,l1+1,l1+llen,l2,l2+llen-1);
           // cout<<"yes"<<endl;
        }
    else
            p->lchild=NULL;
    if(rlen)
        {
            p->rchild=lesson6(a,b,h1-rlen+1,h1,h2-rlen+1,h2);
            //cout<<"no"<<endl;
        }
    else
        {
            p->rchild=NULL;
        }
    return p;

}
void lesson7(Bitree* &head)
{
    Bitree Q[20];
    int f=-1;
    int r=-1;
    Bitree p=*head;
    p.data=1;
    int total;
    Q[++r]=p;
    total=1;
    while(f<r)
        {

            p=Q[++f];
            if(p.lchild)
                {
                    p.lchild->data=p.data*2;
                    Q[++r]=*(p.lchild);
                    total++;
                }
            if(p.lchild!=NULL&&total!=p.lchild->data)
                {
                    cout<<"不完全二叉树";
                    break;
                }
            if(p.rchild)
                {
                    p.rchild->data=p.data*2+1;
                    Q[++r]=*(p.rchild);
                    total++;
                }
            if(p.rchild!=NULL&&total!=p.rchild->data)
                {
                    cout<<"不完全二叉树";
                    break;
                }
        }
    cout<<"完全二叉树";
}

void lesson8(Bitree* &head)
{
    Bitree Q[10];
    int Front=-1;int rear=-1;
    Bitree p=*head;
    Q[++rear]=p;
    int num=0;
    while(Front<rear)
        {
            p=Q[++Front];
            if(p.lchild&&p.rchild)
                {
                    num++;
                }
            if(p.lchild)
                {
                    Q[++rear]=*p.lchild;
                }
            if(p.rchild)
                {
                    Q[++rear]=*p.rchild;
                }
        }
        cout<<"度为2的节点有"<<num<<endl;
}

void lesson9(Bitree* &head)
{
    Bitree *Q[10];
    int Front=-1;int rear=-1;
    Bitree *p=head;
    Q[++rear]=p;
    while(Front<rear)
        {
            p=Q[++Front];

            Bitree* temp=p->rchild;
            p->rchild=p->lchild;
            p->lchild=temp;
            if(p->lchild)
                {
                    Q[++rear]=p->lchild;
                }
            if(p->rchild)
                {
                    Q[++rear]=p->rchild;
                }
        }
        PreOrder(head);
}

void lesson10(Bitree* head,int k)
{
   Bitree *S[10];
   Bitree *p=head;
   int top=-1;
   int num=0;
   while(top!=-1 || p)
    {
        if(p)
            {
                S[++top]=p;
                num++;
                 if(num==k)
                {
                   cout<<p->data;
                }
                p=p->lchild;
            }
        else
            {
                p=S[top--];
                p=p->rchild;
            }

    }

}

void lesson11(Bitree* &head)
{
    if(head)
        {

            if(head->data==3 )
            {
                cout<<"Yes"<<endl;
            }
            else if(head->data==5)
            {
                cout<<"Yes"<<endl;
            }

                lesson11(head->lchild);
                lesson11(head->rchild);

        }



}

void lesson3(Bitree* &head)
{
    Bitree *S[10];
    Bitree *p=head;
    int top=-1;
    Bitree *r=NULL;
    Bitree *m=NULL;
    while(p || top!=-1)
        {
            if(p)
                {
                    if(p->data==7)
                        {
                            while(top!=-1){
                            m=S[top];
                            cout<<m->data;
                            top--;
                            }
                            break;
                        }
                    S[++top]=p;
                    p=p->lchild;

                }
            else
                {
                    p=S[top];
                    if(p->rchild&&p->rchild!=r)
                        {
                            p=p->rchild;


                        }
                    else
                        {
                            p=S[top--];
                            //cout<<p->data<<" ";
                            r=p;
                            p=NULL;
                        }


                }

        }
}

void lesson14(Bitree* &head)
{
    Bitree *Q[10];
    Bitree *p=head;
    int Front=-1;int Rear=-1;
    int maxW=0;
    int last=0;
    Q[++Rear]=p;
    while(Front<Rear)
        {
            p=Q[++Front];
            if(p->lchild)
                {
                    Q[++Rear]=p->lchild;
                }
            if(p->rchild)
                {
                    Q[++Rear]=p->rchild;
                }
            if(Front==last)
                {
                    if(Rear-last>maxW)
                        {
                            maxW=Rear-last;
                        }
                    last=Rear;
                }
        }
        cout<<maxW;
}

void lesson16(Bitree* &head)
{
    Bitree *S[10];
    int top=-1;
    Bitree *p=head;
    Bitree *r=NULL;
    int WPL=0;
    while(p||top!=-1)
        {
            if(p)
                {
                    S[++top]=p;
                    p=p->lchild;
                }
            else
                {
                    p=S[top];
                    if(p->rchild&&p->rchild!=r)
                        {
                            p=p->rchild;
                        }
                    else
                        {
                            p=S[top--];
                            //cout<<p->data;
                            if(p->lchild==NULL)
                                {

                                    WPL+=(top+1)*p->data;
                                }
                            r=p;
                            p=NULL;
                        }
                }
        }
        cout<<WPL;

}

void lesson20(Bitree* &head)
{
    Bitree *S[10];
    int top=-1;
    Bitree *p=head;
    Bitree *r=NULL;
    int oc=0;
    while( p|| top!=-1)
        {
            if(p)
                {
                    if(!p->lchild&&p->rchild)
                        {
                            cout<<"(";
                            oc++;
                        }

                    S[++top]=p;
                    p=p->lchild;
                    if(p!=NULL&&p->lchild==NULL)
                        {
                            cout<<"(";
                            oc++;
                        }
                }
            else
                {
                    p=S[top--];
                    cout<<p->data;
                    if(p==r)
                        {
                            for(int i=oc;i>0;i--)
                                {
                                    cout<<")";
                                    oc--;
                                }
                        }
                    p=p->rchild;
                    if(p!=NULL&&p->rchild==NULL)
                        {
                            r=p;
                        }

                }

        }
}

int insertBST(Bitree* &head,int k)
{
    if(head==NULL)
        {
            Bitree *s=new Bitree;
            s->data=k;
            s->lchild=s->rchild=NULL;
            head=s;
            return 1;
        }
    else if(head->data==k)
        {
            return 0;
        }
    else if(head->data<k)
        {
            return insertBST(head->rchild,k);
        }
    else
        {
            return insertBST(head->lchild,k);
        }


}

void createBST(Bitree* &head,int* k)
{
    for(int i=0;i<6;i++)
        {
            insertBST(head,k[i]);
        }
}

void lesson21(Bitree* &head,int c,int &mmm)
{
    if(head!=NULL)
        {

            lesson21(head->lchild,c+1,mmm);
            lesson21(head->rchild,c+1,mmm);
        }
        else
            {
                if(mmm<c) mmm=c;

            }


}

void lesson24(Bitree* &head)
{
    if(head!=NULL)
        {
            if(head->lchild==NULL && head->rchild==NULL)
                {
                    head=NULL;
                }
            lesson24(head->lchild);
            lesson24(head->rchild);
        }
}
void lesson25(Bitree* &head,int k)
{
    if(head==NULL)
        return;
    if(head->data==5)
        {
            cout<<"第"<<k<<"层"<<endl;
        }
    else
        {
            lesson25(head->lchild,k+1);
            lesson25(head->rchild,k+1);
        }
}

void lesson26(Bitree* &head,int k,int &MaxHeight)
{
    if(head==NULL)
        return;

    if(MaxHeight<k)
        MaxHeight=k;
    lesson26(head->lchild,k+1,MaxHeight);
    lesson26(head->rchild,k+1,MaxHeight);

}

void lesson27(Bitree* &head,int &k)
{
    if(head!=NULL)
        {
            if(head->data>k)
                k=head->data;
            lesson27(head->lchild,k);
            lesson27(head->rchild,k);
        }
}

void lessonlast(Bitree* &head,int k)
{
    if(head!=NULL)
        {
            cout<<head->data<<" "<<k<<endl;
            lessonlast(head->lchild,k+1);
            lessonlast(head->rchild,k+1);
        }
}


int main()
{

    int c[9]={1,2,4,5,6,7,3,8,9};
    int d[9]={4,2,6,5,7,1,8,3,9};

    //int c[3]={1,2,3};
    //int d[3]={2,1,3};
    Bitree *head=lesson6(c,d,0,8,0,8);
    int m=1;

    lessonlast(head,m);

    //InOrder(head);
    }

