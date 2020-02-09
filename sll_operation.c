#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*link;
}node;
node *start=NULL,*ptr,*curptr,*temp;
int i;
void data_call()
{
    temp = (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
}
void insert_beg()
{
    data_call();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->link=start;
        start=temp;
    }
}
void insert_end()
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
void insert_location()
{   int pos,count=0;
    ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        count++;
    }
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg();
    }
    else if(pos==count+1)
    {
        insert_end();
    }
    else if(pos>1 &&pos<=count)
    {   
        data_call();
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;

    }
    

}
void delete_beg()
{
    if(start==NULL)
    {
        printf("\nthe linked list doesn't exist");
    }
    else
    {
        ptr=start;
        start=start->link;
        free(ptr);
    }
}
void delete_end()
{
    if(start==NULL)
    {
        printf("\nthe linked list is exist");
    }
    else
    {   ptr=start;
        while(ptr->link!=NULL)
        {   curptr=ptr;
            ptr=ptr->link;
        }
        curptr->link=NULL;
        free(ptr);

    }
}
void delete_pos()
{
    int pos,count=0;
    ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        count++;
    }
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        delete_beg();
    }
    else if(pos==count)
    {
        delete_end();
    }
    else if(pos>1&&pos<count)
    {   ptr=start;
        for(i=1;i<pos;i++)
        {   temp=ptr;
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        free(ptr);

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
        printf("\n1.insert at beginning\n2.insert at end\n3.insert at any position\n4.delete at beginning\n5.delete at end\n6.delete at position\n7.display\n8.exit\nEnter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_beg();break;
            case 2:insert_end(); break;
            case 3:insert_location(); break;
            case 4:delete_beg();break;
            case 5:delete_end();break;
            case 6:delete_pos();break;
            case 7:display();break;
            case 8:exit(0);break;
            default:printf("Wrong input");
        }
    }
}
