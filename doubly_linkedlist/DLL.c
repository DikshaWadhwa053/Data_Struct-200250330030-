#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node DLL;
DLL *tail,*head=NULL;
int count1=0;

DLL *ForwardLL(DLL *);
void display();
DLL *insert_at_beg(DLL *);
DLL *deletion_at_end(DLL *);
DLL *Backward_Linkedlist(DLL *);
void main()
{
    int choice;
    while(1)
    {
    printf("enter your choice\n");
    printf("1.To create a Forward list\n");
    puts("2. To Display the created list");
    puts("3. Insertion at beginning");
    puts("4. Deletion at ending");
    puts("5. Backward a given linked list");
    puts("6. Exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            head=ForwardLL(head);

        case 2:
            display();
            break;

        case 3:
            head=insert_at_beg(head);
            break;

        
        case 4:
            head=deletion_at_end(head);
            break;

        case 5:
            head=Backward_Linkedlist(head);
            break;
        
        case 6:
            exit(1);

        default:
            puts("invalid choice is entered");
            break;
    }
}
}

DLL *ForwardLL(DLL *head)
{
    head=NULL;
    DLL *newnode;
    int choice=1;
    while(choice){
        newnode=(DLL *)malloc(sizeof(DLL));
        printf("Enter the data of your choice\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do you want to continue press 1 for yes\n");
        //puts("");
        scanf("%d",&choice);


    }
    return head;
   
}


void display()
{   
    printf("The displayed List is:\n");
    DLL *temp;
    temp=head;
    if(head==NULL){
        printf("Linkedlist is empty\n");
    
    }
    
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

DLL *insert_at_beg(DLL *head){
    DLL *newnode,*temp=head;
    newnode=(DLL *)malloc(sizeof(DLL));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    
    newnode->prev=NULL;
    newnode->next=NULL;
 //printf("****");
    if(head==NULL){
        head=newnode;
    }
   

    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    
    return head;
   // temp=head;  

}


DLL *deletion_at_end(DLL *head)
{
    DLL *temp;
    if(tail==NULL)
    puts("list is empty");
    else
{    temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
}
temp=head;
}



DLL *Backward_Linkedlist(DLL *head)
{
    DLL *temp,*current,*nextnode;
    
    if(head==NULL)
    {
        puts("Linked list is empty");
    }   
    else
    {
        current=head;
        while(current!=NULL)
        {
            nextnode=current->next;
            current->next=current->prev;
            current->prev=nextnode;
            current=nextnode;
        }
        current=head;
        head=tail;
        tail=current;
    }
 temp=head;   
}