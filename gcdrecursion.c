#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    if(a==0)
        return b;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    if(b>a)
        return gcd(a,b-a);
}                                                                                      
void main()
{
    int a,b;
    printf("Enter values of two no.s");
    scanf("%d%d",&a,&b);

    printf("\nThe gcd of %d and %d is %d ",a,b,gcd(a,b));
}
