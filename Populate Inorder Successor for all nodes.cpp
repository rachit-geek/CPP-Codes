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

void oxymoron(struct node* root)
{
    if(root==NULL)
        return;
    v.push_back(root);
    oxymoron(root->left);
    oxymoron(root->right);
}

void populateNext(struct node* root)
{
	node* nod=root;
    for(int i=1;(i)<v.size();i++)
    {
        nod->next=v[i];
		nod=nod->next;
    }
}

void preorder(node* root)
{
	if(root==NULL)
		return;
// 	node* nod=root->next;
	cout<<root->data<<" and its next is ";
	if(root->next)cout<<(root->next)->data<<"        ";
	else
	cout<<"nothning    ";
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
    node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->left->right->left=newnode(8);
	root->left->right->right=newnode(7);
	root->right->left=newnode(6);
	root->right->left->right=newnode(9);
	oxymoron(root);
	populateNext(root);
	cout<<"Pre-order is"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"Inorder is"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"Post-order is"<<endl;
	postorder(root);
	cout<<endl;

	
	return 0;
}