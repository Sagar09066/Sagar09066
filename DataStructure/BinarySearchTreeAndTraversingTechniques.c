#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node * left,*right;
};

struct node * insert(int,struct node *);
void Preorder(struct node *);
void inorder(struct node *);
void Postorder(struct node *);
void display(struct node *);
void Freetree(struct node *);

int main()
{
    struct node * tr= NULL;
    int ele,i,num;
    printf("Enter No. of nodes: ");
    scanf("%d",&num);
    for(i = 0;i < num;i++){
        printf("Enter values :");
        scanf("%d",&ele);
        tr = insert(ele,tr);
    }
    printf("Binary tree is : \n");
    display(tr);

    Freetree(tr);

    return 0;
}

struct node * insert(int num, struct node  * tr)
{
    if (tr == NULL)
    {
        tr =(struct node *)malloc(sizeof(struct node));
        tr ->data = num;
        tr ->left = NULL;
        tr ->right= NULL;
    }
    else if (num < tr->data)
    {
        tr ->left = insert(num,tr->left);
    }
    else if (num > tr->data)
    {
        tr ->right = insert(num,tr->right);
    }
    else{
        printf("Duplicate not allowed \n");
    }

    return tr;
}

void Preorder(struct node *tr){
    if(tr!= NULL)
    {
        printf("%d\t",tr ->data);
        Preorder(tr->left);
        Preorder(tr->right);
    }
}

void inorder(struct node *tr){
    if(tr != NULL)
    {
       inorder(tr->left);
       printf("%d\t",tr->data);
       inorder(tr->right);
    } 
}

void Postorder(struct node *tr){
    if(tr != NULL){
        Postorder(tr ->left);
        Postorder(tr ->right);
        printf("%d\t",tr->data);
    }
}

void display(struct node *tr)
{
    printf(" Pre order of tree is : \n");
    Preorder(tr);
    printf("\n inorder of tree is : \n");
    inorder(tr);
    printf("\n Post order of tree is :\n");
    Postorder(tr);
}

void Freetree(struct node * tr)
{
    if(tr != NULL)
    {
        Freetree(tr ->left);
        Freetree(tr ->right);
        free(tr);
    }
}
