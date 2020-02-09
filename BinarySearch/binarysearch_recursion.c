#include<stdio.h>

int binary_search(int arr[],int first,int last,int key)
{
    int mid;
    mid=(first+last)/2;
    if(first>last)
        return -1;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        return binary_search(arr,first,mid-1,key);
    }
    else if(arr[mid]<key)
    {
        return binary_search(arr,mid+1,last,key);
    }
}
void main()
{
    int n,res,i,k;
    printf("\nEnter no. of elements");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter key to be searched:");
    scanf("%d",&k);
    res=binary_search(arr,0,n-1,k);
    if(res==-1)
    {
        printf("\nNo. not found");
    }
    else
    {
        printf("\nNo. found at %d",res+1);
    }
    
}
