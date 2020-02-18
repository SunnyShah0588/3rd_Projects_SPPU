#include<iostream>
#include<fstream>
using   namespace std;

struct node
{
string key,mean;
node *L,*R;
};
class  avl_tree
{

		private:
			node *root;
		public:
			avl_tree()
			{
				root=NULL;
			}

		void create();
		void display();
		void inorder(node *);
		node *LL(node *);
		node *LR(node *);
		node *RR(node *);
		node *RL(node *);
		node *insert(node *,string,string);
		int height(node *);
		int  max(int,int);
};

void  avl_tree::create()
{
fstream f1;
char data[30], key[20], mean[20];
int i,j;
f1.open("a.txt",ios::in);
while(f1)
     {
	f1.getline(data,30);
	if(f1)
		{
		for(i=0;data[i]!=':';i++)
		key[i]=data[i];
		key[i]='\0';
		i++;
		for(j=0;data[i]!='\0';i++,j++)
			mean[j]=data[i];
		mean[j]='\0';
		root=insert(root,key,mean);
		 }

     }
}

void avl_tree::inorder(node *temp)
{
if(temp)
   {
	inorder(temp->L);
	cout<<"\n"<<temp->key<<":"<<temp->mean;
	inorder(temp->R);
   }
}

void avl_tree::display()
{
	inorder(root);
}

node *avl_tree::LL(node *parent)
{
node *temp;
temp=parent->L;
parent->L=temp->R;
temp->R=parent;
return temp;
}

node *avl_tree::RR(node *parent)
{
node *temp;
temp=parent->R;
parent->R=temp->L;
temp->L=parent;
return temp;
}

node *avl_tree::LR(node *parent)
{
parent->L=RR(parent->L);
parent=LL(parent);
return parent;
}

node *avl_tree::RL(node *parent)
{
parent->R=LL(parent->R);
parent=RR(parent);
return parent;
}

int avl_tree::max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

node *avl_tree::insert(node *temp,string keyv,string meanv)
{
	if(temp==NULL)
	{
		temp=new node;
		temp->key=keyv;
		temp->mean=meanv;
		temp->L=temp->R=NULL;
	}
	else
	{
		if(keyv<temp->key)
		{
			temp->L=insert(temp->L,keyv,meanv);
			if(height(temp->L)-height(temp->R)==2 || height(temp->L)-height(temp->R)==-2 )
			{
				if(keyv<temp->L->key)
					temp=LL(temp);
				else
					temp=LR(temp);
			}
		}
		else
		{

			temp->R=insert(temp->R,keyv,meanv);
			if(height(temp->L)-height(temp->R)==2 || height(temp->L)-height(temp->R)==-2 )
			{
				if(keyv>temp->R->key)
					temp=RR(temp);
				else
					temp=RL(temp);
			}
		}

	 }
	return temp;
}


int avl_tree::height(node *temp)
{
if(temp==NULL)
	return -1;
if(temp->L==NULL && temp->R==NULL)
	return 0;
return(1+max(height(temp->L),height(temp->R)));
}


int main()
{
	avl_tree t;
	t.create();
	t.display();
	return 0;

}
