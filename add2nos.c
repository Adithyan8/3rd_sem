#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* addnode(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
        head=temp;
    else
    {
        struct node *temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}

struct node* addnodef(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}

struct node* addint(struct node *nu1,struct node *nu2,struct node *nu3)
{
    struct node *i1=nu1,*i2=nu2,*i3=nu3;
    int c=0,sum,rem,quo;
    while(i1 && i2)
    {
        sum=i1->data + i2->data + c;
        c=sum/10;
        rem=sum%10;
        i3=addnodef(i3,rem);
        i1=i1->next;
        i2=i2->next;
    }

    while(i1)
    {
        sum=i1->data + c;
        rem=sum%10;
        c=sum/10;
        addnodef(i3,rem);
        i1=i1->next;
    }

    while(i2)
    {
        sum=i2->data + c;
        rem=sum%10;
        c=sum/10;
        addnodef(i3,rem);
        i2=i2->next;
    }
    
    return i3;
};
int main()
{
    char *num1="13245337";
    char *num2="12345678";
    struct node *numb1=NULL,*numb2=NULL,*numb3=NULL;
    int n1=strlen(num1),n2=strlen(num2),i;
    for(i=n1-1;i>=0;i--)
        numb1=addnode(numb1,num1[i]-48);
    for(i=n2-1;i>=0;i--)
        numb2=addnode(numb2,num2[i]-48);
    
    numb3=addint(numb1,numb2,numb3);
    struct node *t3=numb3;
    
    while(t3)
    {    printf("%d",t3->data);
         t3=t3->next;
    }     
    return 0;
}
