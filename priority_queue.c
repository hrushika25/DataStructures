#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int pq[MAX],rear=-1,front=-1,data,i,j;
void check(int data)
{
    for(i=front;i<=rear;i++)
    {
        if(data>pq[i])
        {
            for(j=rear;j>=i;j--)
            {
                pq[j+1]=pq[j];
            }
            pq[i]=data;return;
        }
    }
    pq[i]=data;
}
void insert_prior()
{   
    printf("\nEnter data:");
    scanf("%d",&data);
    if(rear==MAX-1)
    {
        printf("Fulllll");
        return;
    }
    else if(front==-1&&rear==-1)
    {
        rear=front=0;
        pq[rear]=data;return;

    }
    else
    {
        check(data);
    }
    rear++;
}

void display()
{   if(front==-1&&rear==-1)
    {
        printf("Empty queue");
    }
    else
    {
         for(i=front;i<=rear;i++)
        {
            printf("%d ",pq[i]);
        }   
    }
}
void delete()
{
    if(rear==-1&&front==-1)
    {
        printf("Queue is empty");
    }
    else if(rear==front)
    {
        rear=front=-1;
    }
    else 
    {
        front++;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_prior(); break;
            case 2:delete(); break;
            case 3:display(); break;
            case 4:exit(0); break;
            default:printf("Wrong input"); break;

        }
    }
}
