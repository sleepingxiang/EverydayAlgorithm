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
void T(string,int&,Bitree* &,Bitree* &);
void E(string,int&,Bitree* &,Bitree* &);
void E_(string,int&,Bitree* &,Bitree* &);
void T_(string,int&,Bitree* &,Bitree* &);
void F(string,int&,Bitree* &,Bitree* &);



void E(string s,int &index,Bitree* &head,Bitree* &p)
{
    //建立一个记忆指针
    Bitree *oldE=p;
    //建造左节点
    Bitree *newNode=new Bitree;
    newNode->data="T";
    newNode->lchild=NULL;
    newNode->mchild=NULL;
    newNode->rchild=NULL;
    p->lchild=newNode;
    p=newNode;
    T(s,index,head,p);
    p=oldE;
    //建右子树
    Bitree *newNode2=new Bitree;
    newNode2->data="E_";
    newNode2->lchild=NULL;
    newNode2->mchild=NULL;
    newNode2->rchild=NULL;
    p->rchild=newNode2;
    p=newNode2;
    E_(s,index,head,p);


}

void E_(string s,int &index,Bitree* &head,Bitree* &p)
{

    if(s[index]=='+')
        {
            Bitree *oldE_=p;
            cout<<"+号匹配成功"<<endl;
            index++;
            //先建左子树
            Bitree *newNode=new Bitree;
            newNode->data="+";
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            //再建中子树
            Bitree *newNode2=new Bitree;
            newNode2->data="T";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            T(s,index,head,p);
            p=oldE_;
            //最后建右子树
            Bitree *newNode3=new Bitree;
            newNode3->data="E_";
            newNode3->lchild=NULL;
            newNode3->mchild=NULL;
            newNode3->rchild=NULL;
            p->rchild=newNode3;
            p=newNode3;
            E_(s,index,head,p);
            p=oldE_;
        }
    else if(s[index]=='-')
        {
            Bitree *oldE_=p;
            cout<<"-号匹配成功"<<endl;
            index++;
              //先建左子树
            Bitree *newNode=new Bitree;
            newNode->data="-";
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            //再建中子树
            Bitree *newNode2=new Bitree;
            newNode2->data="T";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            T(s,index,head,p);
            p=oldE_;
            //最后建右子树
            Bitree *newNode3=new Bitree;
            newNode3->data="E_";
            newNode3->lchild=NULL;
            newNode3->mchild=NULL;
            newNode3->rchild=NULL;
            p->rchild=newNode3;
            p=newNode3;
            E_(s,index,head,p);
            p=oldE_;
        }
    else return;
}

void T(string s,int &index,Bitree* &head,Bitree* &p)
{
    Bitree *oldT=p;
    //建左子树
    Bitree *newNode=new Bitree;
    newNode->data="F";
    newNode->lchild=NULL;
    newNode->mchild=NULL;
    newNode->rchild=NULL;
    p->lchild=newNode;
    p=newNode;
    F(s,index,head,p);
    p=oldT;

    //建右子树
    Bitree *newNode2=new Bitree;
    newNode2->data="T_";
    newNode2->lchild=NULL;
    newNode2->mchild=NULL;
    newNode2->rchild=NULL;
    p->rchild=newNode2;
    p=newNode2;

    T_(s,index,head,p);
    p=oldT;
}

void T_(string s,int &index,Bitree* &head,Bitree* &p)
{

    if(s[index]=='*')
        {
            Bitree* oldT_=p;
            cout<<"*号匹配成功"<<endl;
            index++;
            //先建左子树
            Bitree *newNode=new Bitree;
            newNode->data="*";
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            //再建中子树
            Bitree *newNode2=new Bitree;
            newNode2->data="F";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            F(s,index,head,p);
            p=oldT_;
            //再建右子树
            Bitree *newNode3=new Bitree;
            newNode3->data="T_";
            newNode3->lchild=NULL;
            newNode3->mchild=NULL;
            newNode3->rchild=NULL;
            p->rchild=newNode3;
            p=newNode3;
            T_(s,index,head,p);
            p=oldT_;
        }
    else if(s[index]=='/')
        {
            Bitree* oldT_=p;
            cout<<"/号匹配成功"<<endl;
            index++;
            Bitree *newNode=new Bitree;
            newNode->data="/";
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            //再建中子树
            Bitree *newNode2=new Bitree;
            newNode2->data="F";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            F(s,index,head,p);
            p=oldT_;
            //再建右子树
            Bitree *newNode3=new Bitree;
            newNode3->data="T_";
            newNode3->lchild=NULL;
            newNode3->mchild=NULL;
            newNode3->rchild=NULL;
            p->rchild=newNode3;
            p=newNode3;
            T_(s,index,head,p);
            p=oldT_;
        }
    else
        return;

}

void F(string s,int &index,Bitree* &head,Bitree* &p)
{

    if(s[index]>='a'&&s[index]<='z' || s[index]>='A'&&s[index]<='Z'||s[index]>='0'&&s[index]<='9') //假设index是标识符或者常数。先用单个字符i代替
        {

            cout<<s[index]<<"匹配成功"<<endl;
            index++;
            //建立中子树
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1];
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->mchild=newNode;

        }

    else if(s[index]=='(')
                {
                    Bitree *oldF=p;
                    cout<<"(匹配成功"<<endl;
                    index++;

                    //建立左子树
                    Bitree *newNode=new Bitree;
                    newNode->data="(";
                    newNode->lchild=NULL;
                    newNode->mchild=NULL;
                    newNode->rchild=NULL;
                    p->lchild=newNode;

                    //建立中子树
                    Bitree *newNode2=new Bitree;
                    newNode2->data="E";
                    newNode2->lchild=NULL;
                    newNode2->mchild=NULL;
                    newNode2->rchild=NULL;
                    p->mchild=newNode2;
                    p=newNode2;
                    E(s,index,head,p);
                    p=oldF;
                    if(s[index]==')')
                        {
                            cout<<")匹配成功"<<endl;
                            index++;
                            //建立右子树
                            Bitree *newNode3=new Bitree;
                            newNode3->data=")";
                            newNode3->lchild=NULL;
                            newNode3->mchild=NULL;
                            newNode3->rchild=NULL;
                            p->rchild=newNode3;
                        }
                    else
                        cout<<"error"<<endl;
                }

    else //进入非终结符F以后，既不是括号，也不是i
        cout<<"error-匹配失败"<<endl;
}

  //对一颗树进行层次遍历
void Floor(Bitree *head)
{

    Bitree *Q[50];
    int Front=0;
    int Rear=0;
    //首元素进队
    Q[Front++]=head;
    int layer=1;
    //int floor=6;//层数
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

void Sort(Bitree *head)
{
    if(head!=NULL)
        {
            cout<<head->data<<" ";
            Sort(head->lchild);
            Sort(head->mchild);
            Sort(head->rchild);
        }
        return;
}
int main()
{
    string str="a+b*2/4-(b+c)*3";
    int index=0;
    Bitree *head=new Bitree;
    Bitree *p;
    head->data="E";
    head->lchild=NULL;
    head->mchild=NULL;
    head->rchild=NULL;
    p=head;

    E(str,index,head,p);
    Floor(head);



}
