#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
int s[SIZE],top=-1,num,i;
void push()
{
    if(top==SIZE-1)
    {
        printf("the stack is full");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&num);
        s[++top]=num;
    }
    
}
void pop()
{
    if(top==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        num=s[top--];
        printf("\nthe deleted item is %d",num);
    }
    
}
void display()
{
    if(top==-1)
    {
        printf("\nEmpty stack");
    }
    else
    {
        for(i=top;i!=-1;i--)
        {
            printf("%d ",s[i]);
        }
    }
    
}
void main()
{   int ch;
    printf("\nSTACK OPERATIONS\n");
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                  break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                  break;
        }
    }
}
