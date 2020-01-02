#include<stdio.h>
#include<stdlib.h>

struct node
{
    int pow,coeff;
    struct node *next;
};

struct node* addnode(struct node *head,int coeff,int pow)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->coeff=coeff;
    temp->pow=pow;
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

struct node* multiply(struct node* poly1,struct node* poly2,struct node *poly3)
{
    struct node *p1=poly1,*p2=poly2,*p3=poly3;
    int coeff,pow,flag=0;
    while(p1)
    {
        p2=poly2;
        while(p2)
        {
            coeff=p1->coeff * p2->coeff;
            pow=p1->pow + p2->pow;
            p3=poly3;
            while(p3)
            {
                if(p3->pow == pow)
                {
                    p3->coeff += coeff;
                    flag=1;
                }
                p3=p3->next;
            }
            if(flag==0)
                poly3=addnode(poly3,coeff,pow);
            p2=p2->next;
            flag=0;
        }
        p1=p1->next;
    }
    return poly3;
}

int main()
{
    struct node *poly1=NULL,*poly2=NULL,*poly3=NULL;int n,i,coeff,pow;
    printf("Poly1 :\n");
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coeff and pow : ");
        scanf("%d%d",&coeff,&pow);
        poly1=addnode(poly1,coeff,pow);
    }
    printf("Poly2 :\n");
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coeff and pow : ");
        scanf("%d%d",&coeff,&pow);
        poly2=addnode(poly2,coeff,pow);
    }
    struct node *temp=poly1;i=1;
    while(temp)
    {
        printf("term %d:\nCoeff : %d\nPower : %d\n",i++,temp->coeff,temp->pow);
        temp=temp->next;
    }
    temp=poly2;i=1;
    while(temp)
    {
        printf("term %d:\nCoeff : %d\nPower : %d\n",i++,temp->coeff,temp->pow);
        temp=temp->next;
    }
    poly3=multiply(poly1,poly2,poly3);

    temp=poly3;i=1;
    while(temp)
    {
        printf("term %d:\nCoeff : %d\nPower : %d\n",i++,temp->coeff,temp->pow);
        temp=temp->next;
    }
    return 0;
}
