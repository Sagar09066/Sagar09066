#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 6
int stack[MAX];
int top = 0;

int menu()
{
    int ch;
    printf("\n----Stack Operations Using ARRAY ----");
    printf("\n 1.Push");
    printf("\n 2.Pop");
    printf("\n 3.Display");
    printf("\n 4.Quit");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);

    return ch;
}

void Display()
{
    int i;
    if(top == 0)
    {
        printf("\n\n Stack Empty");
        return;
    }
    else
    {
        printf("\n\nElements in stack : \n");
        for(i = 0;i<top;i++)
        {
            printf("\t%d",stack[i]);
        }
        printf("\n");
    }
}

void Push()
{
    int data;
    if(top == MAX-1)
    {
        printf("\n\n Stack Over Flow");
        return;
    }
    else
    {
        printf("\n Enter data : ");
        scanf("%d",&data);
        stack[top] = data;
        top++;
        printf("\n\n Data pushed into the stack");
    }
}

void Pop(){
    if(top == 0){
        printf("\n Stack Underflow");
    }
    else{
        top--;
        printf("\n Popped element is : %d",stack[top]);
    }
}

int main()
{
    int ch;
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1: Push();
                    break;
            case 2: Pop();
                   break;
            case 3: Display();
                    break;
            case 4: exit(0);
        }
    }while(1);
}
