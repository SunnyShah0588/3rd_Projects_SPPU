#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next,*prev;
};

class cdll
{
    node *header;
public:
    cdll()
    {
        header=NULL;
    }
    void add();
    void display();
    void del();

};
void cdll :: display()
{
   node *temp;
   temp=header;
   cout<<"\nThe List Is:\t\t";
   while(temp->next!=header)
   {
       cout<<temp->data<<"\t\t";
       temp=temp->next;
   }
    cout<<temp->data<<"\t\t";
}

void cdll :: add()
{
    node *nn;
    nn=new node;
    cout<<"\nEnter the Data to Add:";
    cin>>nn->data;
    if(header==NULL)
    {
        header=nn;
        nn->next=nn->prev=nn;
    }
    else
    {
        node *cn;
        cn=header;
        while(cn->next!=header)
        {
            cn=cn->next;
        }
        cn->next=nn;
        nn->prev=cn;
        nn->next=header;
    }
}

void cdll :: del()
{
    int val;
    cout<<"\n Enter the value you want to delete:";
    cin>>val;
    node *cn=header;
    while(cn->data!=val)
    {
        cn=cn->next;
    }
    if(cn==header)
    {
        header=NULL;
        return;
    }
    cn->next->prev=cn->prev;
    cn->prev->next=cn->next;
    cout<<"\n\tThe Node has been deleted";
}

int main()
{
    cdll c;
    while(1)
    {
        int ch;
        cout<<"\n1.Do you Want to Add in List?";
        cout<<"\n2.Do you want to Display the List?";
        cout<<"\n3.Do you want to Delete from List?";
        cout<<"\n4.Exit";
        cout<<"\n\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:c.add();break;
            case 2:c.display();break;
            case 3:c.del();break;
            case 4:return 0;
        }

    }
    return 0;
}
