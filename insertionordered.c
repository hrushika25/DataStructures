#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};
struct node *start,*temp,*ptr;
void data_call()
{
    temp = (struct node*)malloc(sizeof(struct node*));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->llink=temp->rlink=NULL;
}
void insert_order()
{
    data_call();
    if(start==NULL)
    {
        start=temp;
    }
    else if(temp->data<start->data)
    {
        temp->rlink=start;
        start->llink=temp;
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL && ptr->data<temp->data)
        {
            ptr=ptr->rlink;
        }
        if(ptr->rlink==NULL&&ptr->data<temp->data)
        {
            temp->llink=ptr;
            ptr->rlink=temp;
        }
        else
        {
            temp->rlink=ptr;
            ptr->llink->rlink=temp;
            temp->llink=ptr->llink;
            ptr->llink=temp;
        }
        
    }
    
    
}
void display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->rlink;
    }
}
void main()
{   int ch;
    while(1)
    {
        printf("\n1.insert\n2.display\n3.exit\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:insert_order();
                    break;
            case 2:display();
                    break;
            case 3:exit(0);
                    break;
            default:printf("Wrong input");break;
        }
    }

}
