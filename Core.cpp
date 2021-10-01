#include<stdio.h>
#include<stdlib.h>

struct node
{
	int n;
	struct node* next;
};
int s = sizeof(struct node);

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

int main()
{
	
	return 0;
}