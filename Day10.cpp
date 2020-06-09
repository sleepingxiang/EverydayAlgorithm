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
//单词对象，包含种类以及值
struct Token
{
    string data;
    string value;
};


void Cifafenxiqi(string,Token[]);
void D_(Token[],int&,Bitree* &,Bitree* &);
void P(Token[],int&,Bitree* &,Bitree* &);
void D(Token[],int&,Bitree* &,Bitree* &);
void N_(Token[],int&,Bitree* &,Bitree* &);
void Q(Token[],int&,Bitree* &,Bitree* &);
void Stmt(Token[],int&,Bitree* &,Bitree* &);
void B(Token[],int&,Bitree* &,Bitree* &);


void Stmt(Token s[],int &index,Bitree* &head,Bitree* &p)
{
    Bitree *OldStmt=p;
    if(s[index].value=="key"&&s[index].data=="if")
        {

            cout<<s[index].data<<"匹配成功！"<<endl;
            index++;
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1].data;
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;

            Bitree *newNode2=new Bitree;
            newNode2->data="B";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            B(s,index,head,p);
            p=OldStmt;


            Bitree *newNode3=new Bitree;
            newNode3->data="STMT";
            newNode3->lchild=NULL;
            newNode3->mchild=NULL;
            newNode3->rchild=NULL;
            p->rchild=newNode3;
            p=newNode3;
            Stmt(s,index,head,p);
            return;


        }
    else if(s[index].value=="key")
        {

            Bitree *newNode4=new Bitree;
            newNode4->data="D_";
            newNode4->lchild=NULL;
            newNode4->mchild=NULL;
            newNode4->rchild=NULL;
            p->mchild=newNode4;
            p=newNode4;
            D_(s,index,head,p);

        }
}

void B(Token s[],int &index,Bitree* &head,Bitree* &p)
{
    if(s[index].data=="(")
        {
            cout<<s[index].data<<"匹配成功！"<<endl;
            index++;
            Bitree *newNode=new Bitree;
            newNode->data="(";
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            if(s[index].data=="1")
            {
                cout<<s[index].data<<"匹配成功！"<<endl;
                index++;
                Bitree *newNode2=new Bitree;
                newNode2->data="1";
                newNode2->lchild=NULL;
                newNode2->mchild=NULL;
                newNode2->rchild=NULL;
                p->mchild=newNode2;
                if(s[index].data==")")
                    {
                        cout<<s[index].data<<"匹配成功！"<<endl;
                        index++;
                        Bitree *newNode=new Bitree;
                        newNode->data=")";
                        newNode->lchild=NULL;
                        newNode->mchild=NULL;
                        newNode->rchild=NULL;
                        p->rchild=newNode;
                    }
            }
        }
}

void D_(Token s[],int &index,Bitree* &head,Bitree* &p)
{
    Bitree *oldD_=p;
    //建立左子树
    Bitree *newNode=new Bitree;
    newNode->data="D";
    newNode->lchild=NULL;
    newNode->mchild=NULL;
    newNode->rchild=NULL;
    p->lchild=newNode;
    p=newNode;
    D(s,index,head,p);
    p=oldD_;

    //建立右子树
    Bitree *newNode2=new Bitree;
    newNode2->data="P";
    newNode2->lchild=NULL;
    newNode2->mchild=NULL;
    newNode2->rchild=NULL;
    p->rchild=newNode2;
    p=newNode2;
    P(s,index,head,p);
}

void D(Token s[],int &index,Bitree* &head,Bitree* &p)
{
    if(s[index].value=="key")
        {
            cout<<s[index].data<<"匹配成功！"<<endl;
            index++;
            Bitree *oldD=p;
            //建立左子树
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1].data;
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;

            //建立中子树
            Bitree *newNode2=new Bitree;
            newNode2->data="N_";
            newNode2->lchild=NULL;
            newNode2->mchild=NULL;
            newNode2->rchild=NULL;
            p->mchild=newNode2;
            p=newNode2;
            N_(s,index,head,p);
            p=oldD;
            if(s[index].data==";")
                {
                    cout<<s[index].data<<"匹配成功！"<<endl;
                    Bitree *newNode3=new Bitree;
                    newNode3->data=s[index].data;
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


void P(Token s[],int &index,Bitree* &head,Bitree* &p)
{

    if(s[index].value=="key")
        {
            D(s,index,head,p);
            P(s,index,head,p);
        }

   else
    {
        return;
    }

}

void N_(Token s[],int &index,Bitree* &head,Bitree* &p)
{
    if(s[index].value=="id")
        {
            cout<<s[index].data<<"匹配成功！"<<endl;
            index++;
            //建立左子树
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1].data;
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

void Q(Token s[],int &index,Bitree* &head,Bitree* &p)
{
      if(s[index].data==",")
        {
            cout<<s[index].data<<"匹配成功！"<<endl;
            index++;
            Bitree *newNode=new Bitree;
            newNode->data=s[index-1].data;
            newNode->lchild=NULL;
            newNode->mchild=NULL;
            newNode->rchild=NULL;
            p->lchild=newNode;
            if(s[index].value=="id")
                {
                    cout<<s[index].data<<"匹配成功！"<<endl;
                    index++;
                    Bitree *newNode2=new Bitree;
                    newNode2->data=s[index-1].data;
                    newNode2->lchild=NULL;
                    newNode2->mchild=NULL;
                    newNode2->rchild=NULL;
                    p->mchild=newNode2;

                    //建立右子树
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




//该函数用于判断字符串类型的单词是哪种单词
int Print(string s,Token words[],int &index)
{
    string keyword[9]={"int","main","void","string","while","if"," floot","double","else"};

    //关键字的情况
    for(int i=0;i<9;i++)
        {
            if(s==keyword[i])
                {
                    //cout<<"["<<s<<","<<"关键字"<<"]"<<endl;
                    words[index].data=s;
                    words[index++].value="key";
                    return 1;
                }
        }
        return 0;

    //标识符的情况


}


//词法分析，生成单词
void Cifafenxiqi(string s,Token Words[])
{
    int i=0;
    //这个数组用来接收所有单词字符串
    int index=0;

    while(s[i]!='$')
        {
            if(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_')
                {
                    char *x=new char;
                    int numI=0;
                    x[numI]=s[i];
                    i++;
                    //有可能是标识符，也有可能是关键字,这里我打算换一种方法
                    while(s[i]>='A'&&s[i]<='Z' ||s[i]>='a'&&s[i]<='z' || s[i]=='_'|| s[i]>='0'&&s[i]<='9')
                        {

                           x[++numI]=s[i++];
                           //x.to_string();


                        }//while循环结束，该标识符已经结束

                    string word=x; //将x数组复制给一个字符串

                    if(!Print(word,Words,index))
                        {
                           // cout<<"["<<word<<","<<"标识符"<<"]"<<endl;
                            Words[index].data=word;
                            Words[index++].value="id";
                        }



                }
            else if(s[i]>='1'&&s[i]<='9')
                {
                    //常数
                    char *x=new char;
                    int numI=0;
                    x[numI]=s[i];
                    i++;
                    while(s[i]>='0'&&s[i]<='9')
                        {
                            x[++numI]=s[i++];
                        }

                    string word=x;
                   // cout<<"["<<word<<","<<"常数"<<"]"<<endl;
                    Words[index].data=word;
                    Words[index++].value=word;


                }
            else if(s[i]=='{')
                {
                   // cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else if(s[i]==',')
                {
                   // cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else if(s[i]=='}')
                {
                    //cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else if(s[i]=='(')
                {
                    //cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else if(s[i]==')')
                {
                    //cout<<"["<<s[i]<<","<<"分隔符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
                {
                    //cout<<"["<<s[i]<<","<<"运算符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else if(s[i]==';')
                {
                    //cout<<"["<<s[i]<<","<<"运算符"<<"]"<<endl;
                    Words[index].data=s[i];
                    Words[index++].value=s[i];
                    i++;
                }
            else
                {
                    //空格注释等垃圾字符，直接忽略不计
                    i++;

                }
        }


}

int main()
{

    string str="if(1) int pic,pnb;$";
    Token Words[10];
    Cifafenxiqi(str,Words);
    int index=0;
    Bitree *head=new Bitree;
    Bitree *p;
    head->data="STMT";
    head->lchild=NULL;
    head->mchild=NULL;
    head->rchild=NULL;
    p=head;
    Stmt(Words,index,head,p);
    Floor(head);




}
