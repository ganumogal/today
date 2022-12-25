#include<iostream>

using namespace std;

struct node
{
	char key[123];
	char value[123];
	node* L;
	node* R;
};

node*root, *temp;
int count,key;

class bst
{
	public:
	void create();
	void insert(node*, node*);
	void disin(node*);
	void dispre(node*);
	void dispost(node*);
	bst()
	{
	root=NULL;
	count=0;
	}
};

void bst::create()
{
	char ans;
	do
	{
	temp=new node;
	cout<<"\nEnter the key : ";
	cin>>temp->key;
	cout<<"Enter the value: ";
	cin>>temp->value;
	temp->L=NULL;
	temp->R=NULL;
	if(root==NULL)
	{
	root=temp;
	}
	else
	{
	insert(root,temp);
	}
	cout<<"\nDo you want to insert more value : \n";
	cin>>ans;
	count++;
	cout<<endl;
	}while(ans=='y');
	cout<<"\nThe total no of nodes are: "<<count<<endl;
}
void leafdelate(struct tree* root)
{
  if(root==NULL)
      {
         return; 
      }
   else  if(root->right==NULL && root->left==NULL)
          {free(root);}
          root=NULL;
       }
     else  if(root->right==NULL || root->left==NULL)
          {
		if(root->left==NULL)
		{
		root->data=root->right->data;
		free(root->right);}
                root->right=NULL;
	       }
		else if(root->right==NULL)
		{
		root->data=root->left->data;
		free(root->left);}
                root->left=NULL;
	       }
           }
      else
        {
     cout<<"Unable to delate";

        }
		
}	
void bst::insert(node* root, node* temp)
{
	if(temp->key[0] > root->key[0])
	{
		if(root->R==NULL)
		{
		root->R=temp;
		}

		else
		{
		insert(root->R, temp);
		}
	}
	else
	{
		if(root->L==NULL)
		{
		root->L=temp;
		}
		else
		{
		insert(root->L,temp);
		}
	}
}

void bst::disin(node* root)
{
if(root==NULL)
{

return;
}

else
{
disin(root->L);
cout<<"  "<<root->key<<" "<<root->value<<endl;
disin(root->R);
}
}

void bst::dispre(node* root)
{  if(root==NULL)
  {
  return ;
 }
else
{
  cout<<"  "<<root->key<<" "<<root->value<<endl;
  dispre(root->L);
  dispre(root->R);

}
}

void bst::dispost(node* root)
{ if(root==NULL)
{
return;

}else
{
dispost(root->L);
dispost(root->R);
cout<<"  "<<root->key<<" "<<root->value<<endl;
}

}
int main()
{ 
bst b;
int choice;
do
{
cout<<"\n1.Create";
cout<<"\n2.Inorder";
cout<<"\n3.Preorder";
cout<<"\n4.Postorder";
cout<<"\nEnter the choice = ";
cin>>choice;
switch(choice)
{
case 1:b.create();
break;
case 2:b.disin(root);
break;
case 3:b.dispre(root);
break;
case 4:b.dispost(root);
break;
}
}while(choice!=0);

}





















