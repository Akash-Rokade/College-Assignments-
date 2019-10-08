#include<iostream>
using namespace std;
static int l,r;
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}*root,*root1;
class BST
{
	public:
			BST()
			{
				root=NULL;
				root1=NULL;
			}
			struct node *create();
			struct node *insert(struct node*,struct node*);
			struct node *inorder(struct node*);
			struct node *preorder(struct node*);
			struct node *postorder(struct node*);
			int height(struct node*);
			void search(struct node*,int);
			struct node *swap(struct node *);
			int min(struct node*);
			int max(struct node*);
};
struct node *BST::create()
{	struct node *current;
	int info;
	current=new node;
	current->lchild=NULL;
	current->rchild=NULL;
	cout<<"\nEnter Data:";
	cin>>info;
	current->data=info;
	if(root==NULL)
	{
		root=current;
	}
	else
	{
		insert(root,current);
	}
}
struct node *BST::insert(struct node *root,struct node *current)
{
	if(root->data>=current->data)
	{
		if(root->lchild==NULL)
		{
			root->lchild=current;
		}
		else
		{
			insert(root->lchild,current);
		}
	}
	else
	{
		if(root->rchild==NULL)
		{
			root->rchild=current;
		}
		else
		{
			insert(root->rchild,current);
		}
	}
}
struct node *BST::inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		cout<<root->data<<"\t";
		inorder(root->rchild);
	}
}
struct node *BST::preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\t";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

struct node *BST::postorder(struct node *root)
{
	if(root!=NULL)
	{
		
		postorder(root->lchild);
		postorder(root->rchild);
		cout<<root->data<<"\t";
	}
}
int BST::height(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->lchild==NULL && root->rchild==NULL)
	{
		return 1;
	}
	else
	{
		l=height(root->lchild);
		r=height(root->rchild);		
		if(l>=r)
		{
			return (l+1);
		}
		else
		{
			return (r+1);
		}
	}
}
void BST::search(struct node *root,int dat)
{
	if(root->data==dat)
	{
		cout<<"Element Found.";
	}
	else if(root->data<dat && root->rchild!=NULL)
	{
		search(root->rchild,dat);
	}
	else if(root->data>dat && root->lchild!=NULL)
	{
		search(root->lchild,dat);
	}
	else
	{
		cout<<"Element not found.";
	}
}
struct node *BST::swap(struct node *root1)
{
	struct node *temp;
	if(root1!=NULL)
	{
	swap(root1->lchild);
	swap(root1->rchild);
	temp=root1->lchild;
	root1->lchild=root1->rchild;
	root1->rchild=temp;
	}
	return root1;
}
int BST::min(struct node* root)
{
	struct node *current;
	current=root;
	while(current->lchild!=NULL)
	{
		current=current->lchild;
	}
	return current->data;
}
int BST::max(struct node* root)
{
	struct node *current;
	current=root;
	while(current->rchild!=NULL)
	{
		current=current->rchild;
	}
	return current->data;
}
int main()
{
	BST b;
	int ch,Nnodes,dat;
	char c;
	while(1)
	{
	cout<<"\n\n1.Add element.\n2.Display the elements in inorder.\n3.Display the elements in preorder.\n4.Display the elements in postorder.\n5.Max nodes is longest path\n6.Search an element.\n7.Minimum element\n8.Maximum element.\n9.Swap\n10.Exit.\nEnter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:	b.create();
		break;
		case 2:	b.inorder(root);
		break;
		case 3:	b.preorder(root);
		break;
		case 4:	b.postorder(root);
		break;
		case 5:	Nnodes=b.height(root);
			cout<<"Max nodes in longest path is "<<Nnodes;
		break;
		case 6:	cout<<"Enter element to be searched:";
			cin>>dat;
			b.search(root,dat);
		break;
		case 7:	int dat1;
			dat1=b.min(root);
			cout<<"Minimum element is "<<dat1;
		break;
		case 8:	int dat2;
			dat2=b.max(root);
			cout<<"Maximum element is "<<dat2;
		break;
		case 9:	root1=b.swap(root);
			b.inorder(root1);
		break;
		case 10:return 0;
		default:cout<<"You Have Entered Wrong Choice";
		break;
	}
	cout<<"\n";
	}
}
