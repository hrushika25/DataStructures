#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int q[SIZE],rear=-1,front=-1,num;
void insert()
{
    if(rear==SIZE-1)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("\nEnter data: ");
        scanf("%d",&num);
        if(rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        q[rear]=num;
        
    }
    
}
void delete()
{
    if(front==-1&&rear==-1)
    {
        printf("Empty Queue");
    }
    else
    {
        num=q[front];
        printf("\nThe deleted item is %d",num);
        if(front==rear)
            front=rear=-1;
        else
            front++;
    }
}
void display()
{   int i;
    if(rear==-1)
    {
        printf("Empty Queue");
    }
    else
    { 
        for(i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
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
