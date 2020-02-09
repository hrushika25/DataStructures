#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coeff;
    int pow;
    struct node*link;
};

struct node *start=NULL,*ptr,*prev,*temp;

void data_call()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter coefficient and power: ");
    scanf("%d%d",&temp->coeff,&temp->pow);
    temp->link=NULL;
}
void insert()
{
    data_call();
    if(start==NULL)
    {
        start=temp;
    }
    else if(temp->pow<=start->pow)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr!=NULL && ptr->pow<=temp->pow)
        {
            prev=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL&&ptr->pow<=temp->pow)
        {
            prev->link=temp;
        }
        else
        {
            temp->link=prev->link;
            prev->link=temp;
        }
        
    }
    
}
void evaluate()
{
    int sum=0,x;
    printf("\nEnter value of x: ");
    scanf("%d",&x);
    ptr=start;
    while(ptr!=NULL)
    {
        sum=sum+(ptr->coeff*(pow(x,ptr->pow)));
        ptr=ptr->link;
    }
    printf("the evaluation is %d",sum);
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.insert\n2.evaluate\n3.exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:evaluate(); break;
            case 3:exit(0); break;
        }
    }
}
