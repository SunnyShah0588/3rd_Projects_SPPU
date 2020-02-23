#include<iostream>
using namespace std;

class node
{
public:
    string word,mean;
    node *l,*r;
};

class dcll
{
public:
        node *root;
    dcll()
    {
        root=NULL;
    }
    void add();
    void display();
    void inorder(node *);
    void sear();
    void del();
};

void dcll :: inorder(node *temp)
{
    if(temp)
    {
        inorder(temp->l);
        cout<<"\n\t"<<temp->word<<":"<<temp->mean;
        inorder(temp->r);
    }
}
void dcll :: display()
{
    node *temp=root;
    cout<<"\nThe Dictionary is:\n";
    inorder(temp);
}
void dcll :: add()
{
    node *nn,*parent,*temp;
    nn=new node;
    cout<<"\nEnter the Word:    \t";
    cin>>nn->word;
    cout<<"\nEnter the Meaning: \t";
    cin>>nn->mean;
    nn->l=nn->r=NULL;
    if(root==NULL)
    {
        root=nn;
    }
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;
            if(nn->word<temp->word)
                temp=temp->l;
            else
                temp=temp->r;
        }
    if(nn->word<parent->word)
        parent->l=nn;
    else
        parent->r=nn;
    }
}

void dcll :: sear()
{
    node *temp=root;
    string ch;
    cout<<"\nEnter the Word You want to Search for: ";
    cin>>ch;
    while(ch!=temp->word)
    {
        if(ch<temp->word)
            temp=temp->l;
        else
            temp=temp->r;

    }
    if(temp==NULL)
        cout<<"\n\nWord Not Found!!!";
    else
        cout<<"\n\t"<<temp->word<<":"<<temp->mean;
}

void dcll :: del()
{
    node *temp,*parent;
    temp=root;
    string ch;
    cout<<"\nEnter the Word You want to Delete: ";
    cin>>ch;
    while(ch!=temp->word)
    {
        parent=temp;
        if(ch<temp->word)
            temp=temp->l;
        else
            temp=temp->r;
        if(temp==NULL)
            break;

    }
    if(temp==NULL)
        cout<<"\n\nWord Not Found!!!";
    else if(temp->l==NULL && temp->r==NULL)
    {
        if(parent->l==temp)
            parent->l=NULL;
        else
            parent->r=NULL;
    }

    else if(temp->l!=NULL || temp->r!=NULL)
    {
        if(temp->l==NULL)
        {
           if(parent->l==temp)
                parent->l=temp->r;
           else
            parent->r=temp->r;
        }
        else
        {
            if(parent->l==temp)
                parent->l=temp->l;
            else
                parent->r=temp->l;
        }
    }

    else if(temp->l!=NULL && temp->r!=NULL)
    {
        node *t;
        t=temp->l;
        while(t->r)
        {
            t=t->r;
        }
        temp->word=t->word;
        temp->mean=t->mean;
        delete t;

    }
}

int main()
{
    dcll d;int ch;
    char s;
    do
    {
        cout<<"  \t  THIS IS DICTIONARY PROGRAM   ";
        cout<<"\n\t1.Do you want to Add in Dictionary?";
        cout<<"\n\t2.Do you want to Display Dictionary?";
        cout<<"\n\t3.Do you want to Search from Dictionary?";
        cout<<"\n\t4.Do you want to Delete from Dictionary?";
        cout<<"\n\n\tEnter your choice:  ";
        cin>>ch;
        switch(ch)
        {
            case 1:d.add();break;
            case 2:d.display();break;
            case 3:d.sear();break;
            case 4:d.del();d.display();break;
        }
        cout<<"\nDo you want to Continue(Y/N)?: \t ";
        cin>>s;
    }while(s=='y' || s=='Y');
    return 0;
}
