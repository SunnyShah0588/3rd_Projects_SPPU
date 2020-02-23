#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class tnode
{
public:
    string word,mean;
    tnode *L,*R;
};

class avl
{
    tnode *root;
public:
    avl()
    {
        root=NULL;
    }
    void create();
    void display();
    void inorder(tnode *);
    tnode *LL(tnode *);
    tnode *RR(tnode *);
    tnode *LR(tnode *);
    tnode *RL(tnode *);
    int maxi(int,int);
    int height(tnode *);
    tnode *inserti(tnode *,string,string);
};
tnode *avl::LL(tnode *parent)
{
    tnode *temp;
    temp=parent->L;
    parent->L=temp->R;
    temp->R=parent;
    return temp;
}

tnode *avl::RR(tnode *parent)
{
    tnode *temp;
    temp=parent->R;
    parent->R=temp->L;
    temp->L=parent;
    return temp;
}
tnode *avl::LR(tnode *parent)
{
    parent->L=LL(parent->L);
    parent=RR(parent);
    return parent;
}
tnode *avl::RL(tnode *parent)
{
    parent->R=RR(parent->R);
    parent=LL(parent);
    return parent;
}
int avl::maxi(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int avl::height(tnode *temp)
{
    if(temp==NULL)
        return -1;
    if(temp->L==NULL  && temp->R==NULL)
        return 0;
    return(1+maxi(height(temp->L),height(temp->R)));
}
void avl::inorder(tnode *temp)
{
    if(temp)
    {
        inorder(temp->L);
        cout<<"\n\t"<<temp->word<<" : "<<temp->mean;
        inorder(temp->R);
    }
}
void avl::display()
{
    cout<<"\nThe Dictionary is:\n";
    inorder(root);
}
tnode *avl::inserti(tnode *temp,string val,string mval)
{
    if(temp==NULL)
    {
        temp=new tnode;
        temp->word=val;
        temp->mean=mval;
        temp->L=temp->R=NULL;
    }
    else
    {
        if(val<temp->word)
        {
            temp->L=inserti(temp->L,val,mval);
            if(height(temp->L)-height(temp->R)==2)
            {
                if(val<temp->L->word)
                    temp=LL(temp);
                else
                    temp=LR(temp);
            }
        }
        else
        {
            temp->R=inserti(temp->R,val,mval);
            if((height(temp->R)-height(temp->L))==2)
            {
                if(val>temp->R->word)
                    temp=RR(temp);
                else
                    temp=RL(temp);
            }
        }
    }
    return temp;
}

void avl::create()
{
    fstream f;
    char fval[30],val[20],mval[20];
    int i,j,k;
    f.open("dictionary",ios::in);
    while(!f.eof())
    {
        f.getline(fval,30);
        for(i=0;fval[i]!=':';i++)
            val[i]=fval[i];
        val[i]='\0';
        j=i+1;
        for(k=0;fval[j]!='\0';j++,k++)
        {
            mval[k]=fval[j];
        }
        mval[k]='\0';
        cout<<"\n\t"<<val<<" : "<<mval;
        root=inserti(root,val,mval);
    }
}

int main()
{
    avl t;
    t.create();
    t.display();
    return 0;
}
