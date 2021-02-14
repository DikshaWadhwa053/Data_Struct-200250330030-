#include<stdio.h>
#include<stdlib.h>



void enqueue(int );
void dequeue();
void display();
void peek();
void count();
struct node {
    int data;
    struct node *next;
};

typedef struct node QueueLL;
QueueLL *front=NULL;
QueueLL *rear=NULL;

int main()
{
    int choice=0,ch,data;
    printf("Enter 1 for yes and 0 for no\n");
    scanf("%d",&choice);
    while(choice)
    {   printf("enter your choice\n");
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display Operation\n");
        printf("4. Peek Operation\n");
        printf("5. count Operation\n");
        printf("6. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("enter data\n");
                    scanf("%d",&data);
                    enqueue(data);
                    break;

            case 2:
                    dequeue();
                    break;

            
            case 3:
                    printf("the displayed queue is: \n");
                    display();
                    break;

            
            case 4:
                    printf("the peeked element is:");
                    peek();
                    break;

            case 5:
                    printf("the Total count of the queue is:");
                    count();
                    break;

            case 6:
                    exit(1);

            default:
                    puts("invalid input");
        }

    }
}


void enqueue(int item){
    QueueLL *newnode;
    newnode=(QueueLL *)malloc(sizeof(QueueLL));
    newnode->data=item;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    
}

void dequeue()
{
    QueueLL *temp;
    temp=front;
    if(front==NULL && rear ==NULL)
    puts("Underflow Condition\n");
    else
    {
        printf("The dequeued element is: %d\n",front->data);
        front=front->next;
        free(temp);
    }
    
}


void display()
{
QueueLL *temp;
temp=front;
if(front==NULL && rear ==NULL)
    puts("Underflow Condition\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");

}

void peek()
{
    if(front==NULL && rear ==NULL)
    puts("Underflow Condition\n");
    else
    {
        printf("%d\n",front->data);
    }
    
}

void count()
{
    QueueLL *temp;
    temp=front;
    int count=0;
    if(front==NULL && rear ==NULL)
    {
    puts("Underflow Condition So count is 0\n");
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
    }
    printf("%d\n",count);

}