#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};

struct node *start,*ptr,*parent,*temp,*root;

void insert_bs()
{
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
          ptr=root;
          while(ptr!=NULL)
          {
              parent=ptr;
              if(ptr->data == temp->data)
              {
                  printf("\nNode already exits");
                  return;
              }
              else
              {
                  if(temp->data < ptr->data)
                  {
                      ptr=ptr->llink;
                  }
                  else
                  {
                      ptr=ptr->rlink;
                  }
                  
              }
              
          }
          if(temp->data < parent->data)
          {
              parent->llink=temp;
          }
          else
          {
              parent->rlink=temp;
          }
          
    }
    
}
void inorder(struct node *tree)
{
    if(tree != NULL)
    {
        inorder(tree->llink);
        printf("%d ",tree->data);
        inorder(tree->rlink);
    }
}
void main()
{   int n,i;
    printf("enter no. of elements in binary search tree: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        insert_bs();
    }
    printf("\nThe binary search tree is: ");
    inorder(root);
    printf("\n");
}
