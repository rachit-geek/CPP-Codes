#include<stdio.h>
#include<stdlib.h>

struct node
{
	int n;
	struct node* next;
};
int s = sizeof(struct node);
int a[100],b[100];

struct node* createNode()
{
	struct node* temp;
	temp = (struct node *)malloc(s);
	return temp;
}

int get_element(struct node* head, int p)
{
	struct node* temp;
	temp=head;
	for(t=0;t<p;t++)
		temp=temp->next;
	return temp->n;
}

struct node* read_binary_number()
{
	struct node* head;
	head=NULL;
	head = (struct node *)malloc(s);
	struct node* temp;
	temp=head;
	int t=0;
	while(t!=-1)
	{
		scanf(" %d", &t);
		end(head,t);
	}
	return head;
}

void end(struct node* temp, int x)
{
	for(temp->next!=NULL)
		temp=temp->next;
	struct node* temp1;
	temp1 = createNode();
	temp->next=temp1;
	temp1->n=x;
	temp->next=NULL;
	return;
}

void add_binary_number(struct node* head1, struct node* head2)
{
	struct node* temp;
	temp=head1;
	int a1=0;
	while(temp!=NULL)
	{
		a[a1++]=temp->n;
		temp=temp->next;
	}
	temp=head2;
	int b1=0;
	while(temp!=NULL)
	{
		b[b1++]=temp->n;
		temp=temp->next;
	}
	int at,bt;
	for(at=a1, bt=b1;at>0 || bt>0;at--,bt--)
	{
		
	}
}

int main()
{
	for(int t=0;t<100;t++)
	{
		a[t]=0;
		b[t]=0;
	}
    struct node* head1;
	struct node* head2;
    head1=read_binary_number();
	head2=read_binary_number();
	add_binary_number(head1,head2);
	return 0;
}
