#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node * create(struct node *);
struct node * print(struct node *);
struct node * insert_begin(struct node *);
struct node * Insert_MidByPos(struct node * list, int pos);
int search(struct node *,int);
struct node * insert_midbyvalue(struct node *, int);
struct node * insert_end(struct node *);
struct node * delete_first(struct node *);
struct node * delete_last(struct node *);
struct node * delete_bypos(struct node *);
struct node * deleteByValue(struct node *); 

int main(){

    int pos,ele,k,choice;
    struct node * list = NULL;
    char status = 'y';
     
    do{
        printf("*** MENU **** \n 1.Create New LinkedList : \n 2.Insert Element at begin :\n 3.Insert Middle by Position :\n 4.Insert element By value :\n 5.Insert element at end : \n 6.Search Element :\n 7.Delete First Element :\n 8.Delete Last Element: \n 9.Delete by position :\n 10.Delete by value :\n ******  Enter your choice   ***** \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: list = create(list);
                           break;
            case 2: list = insert_begin(list);
                           break;
            case 3: printf("\n Enter the Position = ");
                    scanf("%d", &pos);
                    list = Insert_MidByPos(list,pos);
                           break;
            case 4: printf("\n Enter the element to nsert by value = ");
                    scanf("%d", &ele);
                    list = insert_midbyvalue(list,ele);
                           break;
            case 5: list = insert_end(list);
                           break;
            case 6: printf(" \n*** Searching element *** \n");
                    k = search(list,ele);
                    if(k == 1)
                    {
                        printf("Element Found \n");
                    }
                    else
                    {
                        printf("Element not found \n");
                    }
                    break;
            case 7:list = delete_first(list);
                   break;
            case 8:list = delete_last(list);
                   break;
            case 9:list = delete_bypos(list);
                   break;
            case 10:list = deleteByValue(list);
                   break;
        }

        print(list);
        printf(" \n Do you want to continue press : y ::");
        getchar();
        scanf("%c",&status); 
    }
    while(status == 'y');
}

struct node * create(struct node * list)
{
    struct node *p,*last;
    int num,n,i;
    printf("\n Enter number of nodes : \n");
    scanf("%d",&n);
    for(i = 1;i<=n;i++)
    {
        printf("\n Enter node %d : ",i);
        scanf("%d",&num);
        p = (struct node *)malloc(sizeof(struct node));
        p ->data = num;
        p ->next = NULL;
        if(list == NULL)
        {
            list = p;
        }
        else
        {
            last ->next = p;
        }
        last = p;
    }
    return list;
}

struct node * print(struct node *list)
{
    struct node *p;
    p = list;
    printf("\n List is : \n");
    while(p != NULL)
    {
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

/*
struct node * insert_begin(struct node * list)
{
   struct node * p;
   int num;
   printf("\n Enter new node:");
   scanf("%d", &num);
   p = (struct node *)malloc(sizeof(struct node));
   p -> data = num;
   p ->next = list;
   list = p;

   return list;
}

*/

struct node * insert_begin(struct node *list)
{
    struct node *temp, *new_node;
    int num;
    printf("\n Enter element to insert at begin :\n");
    scanf("%d",&num);

    new_node = (struct node *)malloc(sizeof(struct node));
    temp = list;
    while( temp != NULL)
    {
        if(temp -> data == num){
            printf(" \n Duplicate elements are not allowed \n ");
            free(new_node);
            return list;
        }
        temp = temp ->next;
    }

    new_node ->data = num;
    new_node ->next = list;
    list = new_node;

    return list;
}

struct node * Insert_MidByPos(struct node * list, int pos)
{
    struct node * p, *q;
    int num,i;
    printf("\n Enter the new node = ");
    scanf("%d",&num);
    p = (struct node *)malloc(sizeof(struct node));
    p ->data = num;
    p ->next = NULL;
    q = list;
    for (i = 1; i < pos - 1; i++)
    {
        q = q->next;
    }
    p -> next = q -> next;
    q -> next = p;

    return list;
}

int search(struct node * list, int ele)
{
    struct node * q;
    printf("\n Enter the element to search : ");
    scanf("%d",&ele);
    q=list;
    while(q != NULL && q -> data != ele)
    {
        q = q ->next;
    }

    if(q!=NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node * insert_midbyvalue(struct node * list, int ele){
    int num;
    printf("\n Enter element to insert by value :");
    scanf("%d",&num);
    struct node * temp, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node ->next  = NULL;
    temp = list;
    while(temp != NULL && temp -> data != ele)
    {
        temp = temp -> next;
    }
    if( temp != NULL)
    {
        new_node ->next  = temp -> next;
        temp -> next = new_node;
        return list;
    }
    else
    {
        printf(" List is empty \n ");
    }
}

struct node * insert_end(struct node *list)
{
    struct node * temp,*last;
    int ele;
    printf(" \n Enter element to insert at End  : ");
    scanf("%d",&ele);
    temp = (struct node * )malloc(sizeof(struct node));
    temp -> data = ele;
    temp -> next = NULL;

    if(list == NULL){
        list = temp;
        return list;
    }

    last = list;
    while(last ->next != NULL)
    {
        last = last -> next;
    }
    last -> next = temp;

    return list;
}

struct node * delete_first(struct node * list)
{
    struct node * temp;
    temp = list;
    list = list -> next;
    free(temp);
    return list;
}

struct node * delete_last(struct node * list){

    struct node * temp,*last;

    last = list;
    while(last != NULL && last -> next -> next != NULL){
        last = last-> next;
    }

    temp = last ->next;
    last ->next = NULL;
    free(temp);

    return list;
}

struct node * delete_bypos(struct node * list)
{
    struct node  * temp , * last;
    int i,pos;
    printf("\n Enter position : ");
    scanf("%d",&pos);
    last = list;
    for(i = 1;i<= pos - 2;i++)
    {
        last = last ->next;
    }

    temp = last ->next;
    last ->next = temp ->next;
    free(temp);

    return list;
};

struct node * deleteByValue(struct node * list)
{
    struct node * temp , * last;
    int ele;
    printf("\n Enter element to delete :");
    scanf("%d", &ele);
    temp = list;
    if(list ->data == ele)
    {
        list = delete_first(list);
    }
    else
    {
        last = list;
        
        while (last ->next != NULL && last ->next ->data !=ele)
        {
            last = last ->next;
        }
        if (last -> next != NULL)
        {
            temp = last -> next;
            last ->next = temp -> next;
            free(temp); 
        }
        else{
            printf("\nElement not found in the list.\n");
        }
    }

    return list;
}
