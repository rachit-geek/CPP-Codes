#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,a,n) for(ll i=a;i<n;i++)
#define all(a) a.begin(), a.end()
typedef long long ll;
vector<struct node*> v;

struct node
{
    ll data;
    node *left, *right, *next;
};

node* newnode(ll data)
{
	node * nod=new node;
	nod->data=data;
	nod->left=nod->right=nod->next=NULL;
	return nod;
}

bool mirror(node* r1, node* r2)
{
	if(r1==NULL && r2==NULL)
		return true;
	else if(r1==NULL || r2==NULL)
		return false;
	else
	{
		if((r1->data==r2->data) && mirror(r1->left,r2->right) && mirror(r1->right,r2->left))
			return true;
		else
			return false;
	}
}

void preorder(node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
    ios;
    node* r1=newnode(1);
	r1->left=newnode(2);
	r1->right=newnode(3);
	r1->left->left=newnode(4);
	r1->left->right=newnode(5);
	r1->left->right->left=newnode(8);
	r1->left->right->right=newnode(7);
	r1->right->left=newnode(6);
	r1->right->left->right=newnode(9);
	
	node * r2=newnode(1);
	r2->left=newnode(3);
	r2->right=newnode(2);
	r2->right->left=newnode(5);
	r2->right->right=newnode(4);
	r2->right->left->left=newnode(7);
	r2->right->left->right=newnode(8);
	r2->left->right=newnode(6);
	r2->left->right->left=newnode(9);
	
	cout<<"Inorder is"<<endl;
	inorder(r1);
	cout<<endl;
	
	cout<<"Inorder is"<<endl;
	inorder(r2);
	cout<<endl;
	
	if(mirror(r1,r2))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}