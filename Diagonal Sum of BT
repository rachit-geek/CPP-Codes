#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,a,n) for(ll i=a;i<n;i++)
#define all(a) a.begin(), a.end()
typedef long long ll;
vector<struct node*> v;

ll mi=0;

struct node
{
    ll data,pos;
    node *left, *right;
};

node* newnode(ll data)
{
	node * nod=new node;
	nod->data=data;
	nod->left=nod->right=NULL;
	return nod;
}


void inorder(node* root,ll ans[])
{
	if(root==NULL)
		return;
	inorder(root->left,ans);
	ans[abs(root->pos)]+=root->data;
	inorder(root->right,ans);
}

void diagfill(node* root,ll d)
{
	if(root==NULL)
		return;
	diagfill(root->left,d-1);
	diagfill(root->right,d);
	root->pos=d;
	mi=min(d,mi);
}

int main()
{
    ios;
    node* root=newnode(1);
    root->left=newnode(2); 
    root->right=newnode(3); 
    root->left->left=newnode(9); 
    root->left->right=newnode(6); 
    root->right->left=newnode(4); 
    root->right->right=newnode(5); 
    root->right->left->right=newnode(7); 
    root->right->left->left=newnode(12); 
    root->left->right->left=newnode(11); 
    root->left->left->right=newnode(10);
	diagfill(root,0);
	ll ans[abs(mi)+1];
	memset(ans,0,sizeof(ans));
	cout<<"Inorder is"<<endl;
	inorder(root,ans);
	for(ll i=0;i<(abs(mi)+1);i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}
