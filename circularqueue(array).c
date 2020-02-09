#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int cq[SIZE],rear=-1,front=-1,i,data;
void insert()
{
    if((front==0 && rear==SIZE-1)||(rear==front-1))
    {
        printf("Queue is fulll");
    }
    else
    {
        printf("enter data: ");
        scanf("%d",&data);
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%SIZE;
        cq[rear]=data;
        
    }
    
}
void delete()
{
    if(front==-1&&rear==-1)
    {
        printf("Underflow");
    }
    else
    {
        data=cq[front];
        printf("The deleted item is %d",data);
        if(front==rear)
        {
            rear=front=-1;
        }
        else
        {
            front=(front+1)%SIZE;
        }
        
    }
    
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("CQ is empty");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%SIZE)
        {
        printf("%d",cq[i]);
        }
        printf("%d",cq[i]);
        
    }
    
}
void main()
{
    int ch;
    printf("\nQUEUE OPERATIONS\n");
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                  break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                  break;
        }
    }
}
