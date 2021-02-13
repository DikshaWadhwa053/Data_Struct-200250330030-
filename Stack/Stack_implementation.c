#include<stdio.h>
#include<stdlib.h>
#define N 6

void push();
void pop();
void peek();
void display();
void count();

int stack[N] ;
int top=-1;
int main(){
    int choice=0;
    printf("enter 1 for yes and enter 0 for no\n");
    scanf("%d",&choice);
    while(choice)
    {   int choice1;
        printf("Enter your choice\n");
        printf("1. Push Operation\n");
        puts("2. Pop Operation");
        puts("3. peek Operation");
        puts("4. Display the Stack");
        puts("5. To display the count");
        puts("6. To exit");
        scanf("%d",&choice1);

        switch (choice1)
        {
        case 1:
                push();
                break;

        case 2:
                pop();
                break;
        
        case 3:
                peek();
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

void push()
{
    int x;
    printf("Enter the value uh want to enter into stack\n");
    scanf("%d",&x);
    if(top==N-1)
    puts("The stack is full overflow condition");
    else
    {
        top++;
        stack[top]=x;
    }
    
}

void pop()
{
    int item;
    if(top==-1)
    puts("underflow condition");
    else
    {
        item=stack[top];
        top--;
        printf("The poped element is:%d\n",item);
    }
    
}

void peek()
{
    if(top==-1)
    puts("underflow condition");
    else
    {
        printf("The peeked element is:%d\n",stack[top]);
    }
    
}

void display()
{
    printf("The stack created is:\n");
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void count()
{
    int i,count=0;
    for(i=top;i>=0;i--)
    {
        count++;
    }
    printf("The total no. of elements are :%d\n",count);
}