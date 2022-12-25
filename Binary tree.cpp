#include<iostream>
using namespace std;
struct node
{
	string label;
	int count;
	node *child[50];
};

struct node* create_book(struct node* root)
{
	struct node* nn;
	cout<<"Enter name of a Book=";
	nn=new node;
	cin>>nn->label;
	root = nn;

	cout << "\nEnter the total no.of chapters in book=";
	cin >> root->count;
	for (int i = 0; i<root->count; i++)
	{
		cout << "\nEnter name of chapter " << i + 1 << " => ";
		root->child[i] = new node;
		cin >> root->child[i]->label;

		cout << "\nEnter the total no.of sections in chapter "<<i + 1 << " = ";
		cin >> root->child[i]->count;
		for (int j = 0; j < root->child[i]->count; j++)
		{
			cout << "\nEnter the name of section " << j + 1 << " =>=>";
			root->child[i]->child[j] = new node;
			cin >> root->child[i]->child[j]->label;

			cout << "\nEnter the total no.of subsections in sections " << j + 1 << " = ";
			cin >> root->child[i]->child[j]->count;
			for (int k = 0; k < root->child[i]->child[j]->count; k++)
			{
				cout << "\nEnter name of subsection " << k + 1 << " =>=>=> ";
				root->child[i]->child[j]->child[k] = new node;
				cin >> root->child[i]->child[j]->child[k]->label;
			}
		}
	}
   return root;
}
void display(struct node* root)
{

	node* nn = new node;
	cout << "****************"<<endl;
	cout << "Name of book is = " << root->label<<endl;
	for (int i = 0; i < root->count; i++)
	{
                cout << "Name of chapters => " << root->child[i]->label<<endl;
		for (int j = 0; j < root->child[i]->count; j++)
		{
			cout << "Name of sections =>=> " << root->child[i]->child[j]->label << endl;
			for (int k = 0; k < root->child[i]->child[j]->count; k++)
			{
				cout << "Name of subsection =>=>=>" << root->child[i]->child[j]->child[k]->label<<endl;
			}
		}
	}
}
int main()
{       struct node* root = NULL;
	struct node *temp=create_book(root);
	display(temp);
	return 0;
}