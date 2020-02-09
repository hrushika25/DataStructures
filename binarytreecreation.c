#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};
struct node *root, *tree, *temp;
int isleftchild(struct node *tree)
{   int ch;
    printf("\nDo you want a left child of %d",tree->data);
    printf("\nEnter 1 for Yes and 0 for No: ");
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else
        return 0;
    
}
int isrightchild(struct node *tree)
{   int ch;
    printf("\nDo you want a right child of %d",tree->data);
    printf("\nEnter 1 for Yes and 0 for No: ");
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else
        return 0;
    
}
void create(struct node *tree)
{
    if(isleftchild(tree)==1)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for left child of %d: ",tree->data);
        scanf("%d",&temp->data);
        tree->llink=temp;
        create(temp);
    }
    else
    {
        tree->llink=NULL;
    }
    if(isrightchild(tree)==1)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for right child of %d: ",tree->data);
        scanf("%d",&temp->data);
        tree->rlink=temp;
        create(temp);
    }
    else
    {
        tree->rlink=NULL;
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d ",tree->data);
        inorder(tree->rlink);
    }
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {   
        printf("%d ",tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d ",tree->data);
    }
}
void main()
{
    root = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for first node: ");
    scanf("%d",&root->data);
    root->llink=root->rlink=NULL;

    create(root);
    printf("the inorder of: "); inorder(root);
    printf("the preorder of: "); preorder(root);
    printf("the postorder of: "); postorder(root);
    
}
