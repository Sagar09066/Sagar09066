#include<stdio.h>
#include<conio.h>

#define MAX 5
int Queue[MAX];
int front, rear;

void InsertQueue()
{
    int data;
    if(rear == MAX)
    {
        printf("\n Linear Queue is full");
        return;
    }
    else{
        printf("\n Enter data: ");
        scanf("%d",&data);
        Queue[rear] = data;
        rear++;
        printf("\nData Inserted in the Queue");
    }
}

void DisplayQueue()
{
    int i;
    if(front==rear)
    {
        printf("\n\t Queue is Empty..");
        return;
    }
    else{
        printf("\n Elements in Queue are :\n");
        for(i = front;i<rear;i++){
            printf("%d\t",Queue[i]);
        }
    }
    
}

void DeleteQueue(){
    if (front== rear)
    {
        printf("\n\n Queue is Empty");
        return;
    }
    else{
        printf("\n Deleted element from the Queue is %d ",Queue[front]);
        front++;
    }
}

int menu()
{
    int ch;
    printf("\n ---------***********--------------\n");
    printf("\n ***Queue operations Using Array***\n");
    printf("\n ---------***********--------------\n");
    printf("\n 1.Insert ");
    printf("\n 2.Delete ");
    printf("\n 3.Display ");
    printf("\n 4.Quit");
    printf("\n Enter your choice: ");
    scanf("%d",&ch);

    return ch;
}

int main()
{

    int ch;
    do
    {
        ch = menu();
        switch(ch){
            case 1: InsertQueue();
                    break;
            case 2: DeleteQueue();
                    break;
            case 3: DisplayQueue();
                    break;
            case 4: return 0;
        }
        
    }while(1);
}