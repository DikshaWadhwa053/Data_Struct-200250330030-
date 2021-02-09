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

DLL *create(DLL *);
void display();
void count();
DLL *insert_at_beg(DLL *);
DLL *insert_at_end(DLL *);
DLL *insert_at_pos(DLL *);
DLL *insert_after_a_pos(DLL *);
DLL *deletion_at_beg(DLL *);
DLL *deletion_at_end(DLL *);
DLL *deletion_at_a_pos(DLL *);
DLL *Reversed_Linkedlist(DLL *);
void main()
{
    int choice;
    while(1)
    {
    printf("enter your choice\n");
    printf("1.To create a list\n");
    puts("2. To Display the created list");
    puts("3. Count");
    puts("4. Insertion at beginning");
    puts("5. Insertion at end");
    puts("6. Insertion at a given Position");
    puts("7.Insertion after a given position");
    puts("8. Deletion at beginning");
    puts("9. Deletion at ending");
    puts("10. Deletion at a given position");
    puts("11. Reversing a given linked list");
    puts("12. Exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            head=create(head);

        case 2:
            display();
            break;
        
        case 3:
            count();
            break;

        case 4:
            head=insert_at_beg(head);
            break;

        case 5:
            head=insert_at_end(head);
            break;

        case 6:
            head=insert_at_pos(head);
            break;

        case 7:
            head=insert_after_a_pos(head);
            break;

        case 8:
            head=deletion_at_beg(head);
            break;

        case 9:
            head=deletion_at_end(head);
            break;

        case 10:
            head=deletion_at_a_pos(head);
            break;

        case 11:
            head=Reversed_Linkedlist(head);
            break;
        
        case 12:
            exit(1);

        default:
            puts("invalid choice is entered");
            break;
    }
}
}

DLL *create(DLL *head)
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
        printf("Do you want to continue\n");
        puts("press 1 for yes");
        puts("press 0 for no");
        scanf("%d",&choice);


    }
    return head;
   
}


void display()
{
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

void count()
{
    int count=0;
    DLL *temp;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("the total no. of elements in the ll is :%d\n",count);
    count1=count;

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

DLL *insert_at_end(DLL *head)
{
    DLL *newnode,*temp;
    newnode=(DLL *)malloc(sizeof(DLL));
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    temp=head;
}

DLL *insert_at_pos(DLL *head){
    int pos,i=1;
    DLL *newnode,*temp=head;
    printf("enter your position\n");
    scanf("%d",&pos);
    
    if(pos < 1 || pos > count1)
    printf("invalid position\n");
    else if(pos==1)//only 1 element

    {
        head==NULL;
        insert_at_beg(head);
    }

    else
    {
        newnode=(DLL *)malloc(sizeof(DLL));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
        temp=head;
    }
    
}

DLL *insert_after_a_pos(DLL *head){
    int pos,i=1;
    DLL *newnode,*temp=head;
    printf("enter your position\n");
    scanf("%d",&pos);
    
    if(pos < 1 || pos > count1)
    printf("invalid position\n");

    else
    {
        newnode=(DLL *)malloc(sizeof(DLL));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
        temp=head;
    }
    
}

DLL *deletion_at_beg(DLL *head)
{
    DLL *temp=head;
    
    if (head==NULL)
    puts("list is empty");
    else
    {
        //temp=head;
        head=head->next;
        //temp->next->prev=NULL;
        head->prev=NULL;
        free(temp);
    }
    temp=head;
    
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

DLL *deletion_at_a_pos(DLL *head)
{
    int i=1,pos;
    DLL *temp = head;
    printf("enter your position from where you want to delete\n");
    scanf("%d",&pos);
    if(pos==1)
    {   
        printf("inside if\n");
        
        deletion_at_beg(head);
    }
    else if(pos==count1){
        deletion_at_end(head);
       }
    else
    {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }

    temp=head;
}

DLL *Reversed_Linkedlist(DLL *head)
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