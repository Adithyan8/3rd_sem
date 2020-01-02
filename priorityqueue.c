//Make it a menu-driven program

#include<stdio.h>

int count=0,capacity;
int arr[40];

void heapify(int pos)
{
    int max=pos,temp;
    int l=2*pos+1;
    int r=2*pos+2;
    
    if(l<count && arr[l]>arr[max])
        max=l;
    if(r<count && arr[r]>arr[max])
        max=r;
        
    if(max!=pos)
    {
        temp=arr[max];
        arr[max]=arr[pos];
        arr[pos]=temp;
        heapify(max);
    }
}

void buildheap()
{
    for(int i=count/2;i>=0;i--)
        heapify(i);
}

void insert()
{
    //int i=count++-1;
    /*while(i>0 && data>arr[(i-1)/2])
    {
        arr[i]=arr[(i-1)/2];
        i=(i-1)/2;
    }*/    
    printf("Enter the no. of elements in the heap : ");
    scanf("%d",&count);
    for(int i=0;i<count;i++)
        scanf("%d",&arr[i]);
    buildheap();
}

void delet()
{
    arr[0]=arr[count-1];
    count--;
    
    heapify(0);
}

void display()
{
    if(count==0)
        printf("No queue.\n");
    else
    {
        for(int i=0;i<count;i++)
            printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    insert();
    display();
    delet();
    display();
}