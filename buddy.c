#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;int size;enum{fre,occ,spl}status;
	struct node *left,*right;
};	

struct node *addnode(struct node *head)
{
	struct node* t1=(struct node*)malloc(sizeof(struct node));
	struct node* t2=(struct node*)malloc(sizeof(struct node));

	t1->status=fre;
	t2->status=fre;
	head->status=spl;
	t1->size=t2->size=head->size/2;
	t1->left=t1->right=t2->left=t2->right=NULL;

	head->left=t1;
	head->right=t2;
	return head;
}	

int insert(struct node *head,int data,int size)
{
	if(head->status==occ)
		return 0;
	else if(size>head->size)
		return 0;
	else if(size== head->size || size>head->size/2)
	{
		if(head->status==fre)
		{
			head->status=occ;
			head->data=data;
			return 1;
		}
		else
			return 0;
	}
	else if(size<=head->size/2)
	{
		if(head->status==fre)
		{
			addnode(head);
			return insert(head->left,data,size);
		}
		else
		{
			if(insert(head->left,data,size))
				return 1;
			return insert(head->right,data,size);
		}
	}
}

struct node *search(struct node* head, int key)
{
	 if(head->data == key)
		return head;
	else if(head->status==occ || head->status==fre)
		return NULL;
	else if(head->status == spl)
	{
		if(head->left->data == key)
			return head;
		else if(head->right->data == key)
			return head;
	}	
	struct node*p=search(head->left,key),*q=search(head->right,key);
	if(p!=NULL)
		return p;
	return q;
}

int delet(struct node *head,int key)
{
	struct node* temp=search(head,key);
	if(temp == NULL)
		return 0;
	else
	{
		if(temp->data == key)
			temp->status=fre;
		else if(temp->left->data==key)
			temp->left->status=fre;
		else if(temp->right->data==key)
			temp->right->status=fre;

		if(temp->left->status==fre && temp->right->status==fre)
			temp->status=fre;
		return 1;
	}
}

void display(struct node *head)
{
	if(head->status == fre)
		printf("No data,%d.\n",head->size);
	else if(head->status == occ)
		printf("%d,%d\n",head->data,head->size);
	else
	{
		display(head->left);
		display(head->right);
	}
}

int main()
{
	int size,ch,data;
	printf("Enter the total size : ");
	scanf("%d",&size);
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->status=fre;
	head->size=size;
	head->left=head->right=NULL;

	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data and size : ");
				scanf("%d%d",&data,&size);
				if(insert(head,data,size))
					printf("Memory allocated\n");
				else
					printf("Memory not allocated\n");
				break;
			case 2:
				printf("Enter the data to be deleted : ");
				scanf("%d",&data);
				if(delet(head,data))
					printf("Data deleted.\n");
				else
					printf("Data not found.\n");
				break;
			case 3:display(head);
			       break;
			case 4:exit(0);
			default:printf("Incorrect option.");
		}

	}
}	
					





