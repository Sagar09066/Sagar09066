#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[20],i,n,j,key;
    printf("Enter the Number of elements : \n");
    scanf("%d",&n);
    
    printf("Enter the Elements Values : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 1;i < n ; i++){
        key = a[i];
        for(j = i - 1;j >= 0 && key < a[j];j--){
            a[j + 1] = a[j];
            a[j] = key;
        }
    }

    printf("The elements After Sorting : \n");
    for(i = 0;i < n;i++){
        printf("%d ",a[i]);
    }  
}
