#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
struct node *start,*prev,*cur,*next,*temp,*ptr; 
void data_call()
{   temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
}
     
void insert()
{
    data_call();
     if(start==NULL)
    {
        start=temp;
    }
    else
    {   ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }    

}
struct node * reverse()
{
    if(start==NULL)
    {   
        printf("Linked lists doesn't exist\n");
        return NULL;
    }
    else
    {
        prev=NULL;
        cur=start;
        next=NULL;
        while(cur!=NULL)
        {   next=cur->link;
            cur->link=prev;
            
            prev=cur;
            cur=next;
        }
        return prev;
    }
}
void display()
{
    ptr=start;
    while(ptr->link!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("%d",ptr->data);
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.insert at end\n2.reverse\n3.display\n4.exit\nEnter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:start=reverse(); break;
            case 3:display();break;
            case 4:exit(0);break;
            default:printf("Wrong input");
        }
    }
}
