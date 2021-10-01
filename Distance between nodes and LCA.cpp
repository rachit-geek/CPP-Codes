#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,a,n) for(ll i=a;i<n;i++)
#define all(a) a.begin(), a.end()
typedef long long ll;
vector<struct node*> v;

ll ma=0;

struct node
{
    ll data,level;
    node *left, *right;
};

node* newNode(ll data)
{
	node * nod=new node;
	nod->data=data;
	nod->left=nod->right=NULL;
	return nod;
}


void inorder(node* root,ll lvl)
{
	if(root==NULL)
		return;
	inorder(root->left,lvl+1);
	root->level=lvl;
	inorder(root->right,lvl+1);
}

node* lca(node* root,ll n1,ll n2)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;
	node* llca=lca(root->left,n1,n2);
	node* rlca=lca(root->right,n1,n2);
	if(llca && rlca)
		return root;
	return (llca!=NULL)?llca:rlca;
}

ll dist(node* root,ll d)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* nod=q.front();
        q.pop();
        if(nod->data==d)
            return nod->level;
        if(nod->left)
            q.push(nod->left);
        if(nod->right)
            q.push(nod->right);
    }
}

void distance(node* root, ll n1, ll n2)
{
    inorder(root,0);
    node* nod=lca(root,n1,n2);
    ll d1,d2,d3;
    d1=nod->level;
    d2=dist(root,n1);
    d3=dist(root,n2);
    cout<<"The distance between nodes "<<n1<<" and "<<n2<<" is "<<d2+d3-2*d1<<"."<<endl;
    return;
}

int main()
{
    ios;
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    
    distance(root,4,5);
    distance(root,4,6);
    distance(root,3,4);
    distance(root,2,4);
    distance(root,8,5);
	return 0;
}