#include<iostream>
#include<string.h>
using namespace std;


struct node
{
   char data;
   struct node* right;
   struct node* left;
};

class tree
{
  struct node* root,f;
  public:
        tree()
        {
          root=NULL;
         
        }
        struct node* convert(char exp[]);
        void display(struct node* );
        void del(struct node*);
        void postfix(struct node*);
};
class stack
{
  struct node * S[30];
  int top;
  public :
         stack()
         {
             for(int i=0;i<=30;i++)
                  {
                  
                    S[i]=NULL;
                  
                  
                  }       
                  top=-1;
  
         }
         
    int isempty();
    void push(struct node* n1);
    struct node* pop();
  
};


void stack:: push(struct node * n1)
{ 
 top++;
 S[top]=n1;
}

int stack::isempty()
{  
     if(top==-1)
     {
       return 1;

     }
    else
     {

       return 0;

     }
}

struct node * stack:: pop()
{ 
   
           struct node *temp=NULL;
           temp=S[top];
           top--;
           return temp;
  
}
struct node* tree::convert(char exp[])
{
  
int len,i;
len=strlen(exp);
stack s1;
struct node* nn=NULL;
struct node* t1=NULL;
struct node* t2=NULL;
struct node* t3=NULL;


     for(i=len-1;i>=0;i--)
       {
           nn=new node;
           nn->data=exp[i];
           nn->left=NULL;
           nn->right=NULL;
           
           
           if(isalpha(exp[i]))
              {
                  s1.push(nn);
              }
           else
              {
             
                        t1=s1.pop();
                        t2=s1.pop();
                        nn->left=t1;
                        nn->right=t2;
                        s1.push(nn);
                         
              } 

        }
        t3=s1.pop();
        
    return t3;     
}
void tree::display(struct node *root)
{
   if(root==NULL)
   {
   
   return;
   
   }
   else
    {
      
      display(root->left);
      cout<<root->data;
      display(root->right);
    
    
    }



}
void del(struct node* root)
{
   if(root==NULL)
      {
      return;
      }
   else
      {
      
         del(root->left);
         del(root->right);
         free(root);
      
      
      }    


}
void tree::postfix(struct node* root)
{
   stack s1,s2;
   struct node* t=NULL;
   struct node* temp=NULL;
   struct node* t3=NULL;
   t=root;
   s1.push(t);
   
   
   while(!s1.isempty())
        {
        
           temp=s1.pop();
           s2.push(temp);
          
           if(temp->left!=NULL)
               {
               
                s1.push(temp->left);
                
               
               }
           if(temp->right!=NULL)
               {
               
                 s1.push(temp->right);
               
               
               }    
        }
        while(!s2.isempty())
             { t3=s2.pop();
               cout<<t3->data;
             
             
             }        
        
        
      





}
int main()
{  cout<<"          Program to convert prefix equation to postfix equation         "<<endl;
 tree t;
 struct node* Final=NULL;
 char exp[30];
 cout<<"Enter your prefix expression"<<endl;
 cin>>exp;

 Final=t.convert(exp);
 
cout<<"Your expression on postfix format==   "; 
t.postfix(Final);cout<<"  ";
return 0;

}


