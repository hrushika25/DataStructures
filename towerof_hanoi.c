#include<stdio.h>
char A[],B[],C[],source,temp,destination;
int n;
void toh(int n,char source,char temp,char destination)
{
    if(n==1)
    {
        printf("\nMove disk from %c to %c",source,destination);
    }
    else
    {
        toh(n-1,source,destination,temp);
        printf("\nMove disk from %c to %c",source,destination);
        toh(n-1,temp,source,destination);
    }
    
}
void main()
{
    n=3;
    toh(n,'A','B','C');
}
