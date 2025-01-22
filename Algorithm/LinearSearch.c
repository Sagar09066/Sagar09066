
/* A non-recursive program for Linear Search */

#include<stdio.h>
#include<conio.h>

int main()
{
    int number[25],n,data,i,flag = 0;

    printf("\n Enter the number of elements: ");
    scanf("%d",&n);

    printf("\nEnter the elements:");
    for(i=0;i<n;i++){
        printf("\nEnter Element %d :",i+1);
        scanf("%d",&number[i]);
    }
    printf("Enter the elements to be Searched:");
    scanf("%d",&data);
    for(i=0;i<n;i++)
    {
        if(number[i] == data){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("\nData found at location: %d", i+1);
    }
    else{
        printf("\n Data not found");
    }
}

/* A recursive program for Linear Search */

#include<stdio.h>
#include<conio.h>

void linear_search(int a[],int data,int position,int n){
    if(position < n){
        if(a[position] == data){
            printf("\n Data found at %d :",position + 1);
        }
        else{
            linear_search(a,data,position+1,n);
        }
    }
    else{
        printf("\n Data not found");
    }
}

int main()
{
    int a[25],i,n,data;
    printf("\n Enter the number of elements : ");
    scanf("%d",&n);
    printf("\n Enter the Elements :");
    for (i=0;i<n;i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n Enter the element to be seached : ");
    scanf("%d",&data);
    linear_search(a,data,0,n);
}
