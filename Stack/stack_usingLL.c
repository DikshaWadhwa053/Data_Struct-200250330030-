#include<stdio.h>
#include<stdlib.h>
//#define N 7
struct node{
    int data;
    struct node *next;
};

typedef struct node STACKLL;
STACKLL *top= NULL;

void push(int item);
void pop();
void peek();
void display();
void count();

int main(){
    int choice=0,choice1,data;
    printf("press 1 for yes and 0 for no\n");
    scanf("%d",&choice);
    while(choice)
    {
    puts("enter your choice");
    puts("press 1 to push");
    puts("press 2 to pop");
    puts("press 3 to peek");
    puts("press 4 to display");
    puts("press 5 to count");
    puts("press 6 to exit");
    scanf("%d",&choice1);

    switch(choice1)
    {
        case 1:
                printf("enter the data you want to enter\n");
                scanf("%d",&data);
                push(data);
                display();
                break;

        case 2:
                pop();
                display();
                break;
        
        case 3:
                peek();
                display();
                break;

        case 4:
                display();
                break;

        case 5:
                count();
                break;

        case 6:
                exit(1);

        default:
                puts("invalid input");
                break;
    }

    
    }
}
void push(int item)
{   
    STACKLL *newnode;
    newnode=(STACKLL *)malloc(sizeof(STACKLL));
    
    if(newnode ==NULL)
    {
        printf("Overflow condition");

    }
    
    else
    {
        newnode->data=item;
        newnode->next=top;
        top=newnode;

    }


}

void pop()
{
    STACKLL *temp;
    if(top==NULL)
    puts("Underflow Condition");
    else
    {
        temp=top;
        printf("the top most element poped out of stack is %d\n",top->data);
        top=top->next;
        free(temp);
    }
    
}

void peek()
{
    if(top==NULL)
    puts("Underflow condition");
    else
    {
        printf("The top most peeked element is %d\n",top->data);
    }
    
}

void display()
{
    STACKLL *temp;
    if(top==NULL)
    puts("Underflow Condition");
    else
    {
    temp=top;
    printf("The stack is:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
    
}

void count()
{
    STACKLL *temp;
    int count=0;
    temp=top;
    if(top==NULL)
    puts("Underflow Condition");
    else
    {
    while(temp!=NULL)
    {   temp=temp->next;
        count++;
    }
    }

    printf("The total count of the stack is:%d\n",count);
}