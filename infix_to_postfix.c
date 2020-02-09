#include<stdio.h>
#include<ctype.h>
#define SIZE 30

char infix[SIZE],postfix[SIZE],s[SIZE],ch,temp;
int top=-1,i=0,j=0;
void push(char ch)
{
    s[++top]=ch;
}
char pop()
{
    temp=s[top--];
    return temp;
}
int isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%')
        return 1;
    else
        return 0;
}
int precedence(char ch)
{
    switch(ch)
    {
       case '^':return 5; break;
       case '/':
       case '*':return 4; break;
       case '+':
       case '-':return 3; break;
       case '%':return 2; break;
       default: return 1; break;

    }
}
void main()
{
    printf("\nEnter infix expression: ");
    gets(infix);
    
    while(infix[i]!='\0')
    {
        ch=infix[i];

        if(isalpha(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(isoperator(ch)==1)
        {
            if(ch!='^')
            {
                while(precedence(s[top])>=precedence(ch))
                {
                    postfix[j]=pop();
                    j++;
                }
            }
            push(ch);
        }
        else if(ch==')')
        {   while(s[top]!='(')
            {
                postfix[j]=pop();
                j++;
            }
            temp=pop();
        }
        else 
            printf("\nWrong input");

        i++;
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    printf("\n the postfix expression is:");
    puts(postfix);
}
