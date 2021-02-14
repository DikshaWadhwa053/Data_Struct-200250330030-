#include<stdio.h>
#include<stdlib.h>
#define N 6
int queue[N];
int front =-1;
int rear =-1;

void enqueue(int );
void dequeue();
void display();
void peek();
void count();

void main(){
    int choice=0;
    printf("enter 1 for yes and 0 for no\n");
    scanf("%d",&choice);
    int ch,data;
    while(choice)
    {
        printf("enter your choice of operation\n");
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display the queue\n");
        printf("4. Peek Operation\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter your data\n");
                    scanf("%d",&data);
                    enqueue(data);
                    break;

            case 2:
                    dequeue();
                    break;
            

            case 3:
                    printf("The queue displayed is:\n");
                    display();
                    break;

            case 4:
                    printf("The peeked element is:\n");
                    peek();
                    break;

            case 5:
                    printf("Total Count is:");
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

void enqueue(int item)
{
 if(rear==N-1)
 {
     puts("Overflow Condition");
 }  
 else if(front==-1&&rear==-1)
 {
     front=rear=0;
     queue[rear]=item;
 } 
else
{
    //front=0;
    rear++;
    queue[rear]=item;
}
}

void dequeue()
{
    if(front ==-1 && rear == -1)
    puts("Underflow Condition");
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("the dequeued element is %d\n",queue[front]);
        front++;
    }
    
}

void display(){
    int i;
    if(front == -1 && rear == -1)
    puts("Underflow Condition");
    else
    {
        for(i=front;i<rear+1;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    printf("\n");
}


void peek()
{
    if(front == -1 && rear == -1)
    puts("Underflow Condition\n");
    else
    {
        printf("The peeked element is:%d\n",queue[front]);
    }
    
}

void count()
{
    int count=0,i;
    if(front == -1 && rear == -1)
    puts("Underflow Condition");
    else
    {
        for(i=front;i<rear+1;i++)
        {
            count++;
        }
    }
    printf("%d\n",count);
    
}