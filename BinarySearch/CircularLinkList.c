#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
struct node *last=NULL,*temp,*ptr,*curptr;

void data_call()
{
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
}
void insert_end()
{
    data_call();
    if(last==NULL)
    {
        last=temp;
        last->link=temp;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
        last=temp;
    }
}
void insert_beg()
{
    data_call();
    if(last==NULL)
    {
        last=temp;
        last->link=temp;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
    }
}
void delete_beg()
{
  if(last==NULL)
  {         
       printf("Empty list");
  }
  else
  {
     ptr=last->link;
     last->link=ptr->link;
     free(ptr);
  }
}
void delete_end()
{
     if(last==NULL)
    {         
        printf("Empty list");
    }
    else
    {
        ptr=last->link;
        while(ptr->link!=last)
        {
            ptr=ptr->link;
        }
        ptr->link=last->link;
        free(last);
        last=ptr;
    }
}
void insert_pos()
{
    int count=0,pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    ptr=last->link;
    while(ptr!=last)
    {
        count++;
        ptr=ptr->link;
    }
    count++;
    if(pos==1)
    {
        insert_beg();
    }
    else if(pos==count+1)
    {
        insert_end();
    }
    else if(pos>1&&pos<=count)
    {   data_call();
        ptr=last->link;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void delete_pos()
{
    int count=0,pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    ptr=last->link;
    while(ptr!=last)
    {
        count++;
        ptr=ptr->link;
    }count++;
    if(pos==1)
    {
        delete_beg();
    }
    else if(pos==count)
    {
        delete_end();
    }
    else if(pos>1&&pos<count)
    {   ptr=last->link;
        for(i=1;i<pos;i++)
        {   curptr=ptr;
            ptr=ptr->link;
        }
        curptr->link=ptr->link;
        free(ptr);
    }

}
void delete_data()
{
    int item;
    printf("Enter data to be deleted: ");
    scanf("%d",&item);
    ptr=last->link;curptr=last;
    if(curptr->data==item)
    {
        if(curptr->link==curptr)
        {   
            free(curptr);
            curptr=NULL;
        }
        else
        {
            delete_end();
        }
    }
    else
    {   ptr=last->link;
        curptr=last;
        while(ptr!=last)
        {
            if(ptr->data==item)
            {
                curptr->link=ptr->link;
            }
            curptr=curptr->link;
            ptr=ptr->link;
        }
    }
    

    
}
void display()
{
    ptr=last->link;
    while(ptr!=last)
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
        printf("\n1.insert at beginning\n2.insert at end\n3.insert at any position\n4.delete at beginning\n5.delete at end\n6.delete at position\n7.delte using item\n8.display\n9.exit\nEnter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_beg();break;
            case 2:insert_end(); break;
            case 3:insert_pos(); break;
            case 4:delete_beg();break;
            case 5:delete_end();break;
            case 6:delete_pos();break;
            case 7:delete_data(); break;
            case 8:display();break;
            case 9:exit(0);break;
            default:printf("Wrong input");
        }
    }
}
