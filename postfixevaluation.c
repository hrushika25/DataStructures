#include<stdio.h>
#include<ctype.h>
#define SIZE 30
char postfix[SIZE],ch;
int s[SIZE],num,top=-1,res,op1,op2,i=0;
void push(int num)
{
    s[++top]=num;
}
int pop()
{
    return s[top--];
}
void main()
{
    printf("enter postfix expression\n");
    gets(postfix);
    while(postfix[i]!='\0');
    {
        ch=postfix[i];
        if(isalpha(ch))
        {
            printf("enter value for %c",ch);
            scanf("%d",&num);
            push(num);
        }
        else 
        {
            op2=pop();
            op1=pop();
            switch(ch)
            {
                case '*': res=op1*op2;
                        push(res);
                        break;
                
                case '/': res=op1/op2;
                        push(res);
                        break;
                
                case '+': res=op1+op2;
                        push(res);
                        break;
                
                case '-': res=op1-op2;
                        push(res);
                        break;
                
                case '^': res=op1^op2;
                        push(res);
                        break;
                
                case '%': res=op1%op2;
                        push(res);
                        break;
            }
        }
        i++;
    }
    res=pop();
    printf("\nthe postfix evaluation is %d",res);
}
