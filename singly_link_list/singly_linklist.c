#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct node{
    int data;//data part
    struct node *next;//address of next node of type struct node

};
typedef struct node Node;
Node *create_list(Node *);
void display(Node *);
void count(Node *);
Node *Insertion_at_beg(Node *);
Node *Insertion_at_end(Node *);
Node *Insertion_in_a_given_position(Node *);
Node *Deletion_at_beg(Node *);
Node *Deletion_at_end(Node *);
Node *Deletion_at_specified_position(Node *);
Node *Reversing_the_linked_list(Node *);
//memory is not allocated yet
//only defination
//Node *head=NULL;
int count1=0;
int main(int argc, char const *argv[])
{

Node *head=NULL;
int choice;
while(1){
    printf("1.Create list\n");
    printf("2.Display\n");
    printf("3.Count\n");
    printf("4. Insertion at beginning\n");
    printf("5. Insertion at end \n");
    printf("6. Insertion at a given position\n");
    printf("7. Deletion at beginning\n ");
    printf("8. Deletion at end\n");
    printf("9. Deletion at specified position\n");
    printf("10. Reversing the linked list\n");
    printf("11. Quit\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        head=create_list(head);
        break;

    case 2:
        display(head);
        break;

    case 3:
        count(head);
        break;

    case 4:
        head=Insertion_at_beg(head);
        break;

    case 5:
        head=Insertion_at_end(head);
        break;

    case 6:
        head=Insertion_in_a_given_position(head);
        break;

    case 7:
        head=Deletion_at_beg(head);
        break;

    case 8:
        head=Deletion_at_end(head);
        break;

    case 9:
        head=Deletion_at_specified_position(head);
        break;

    case 10:
        head=Reversing_the_linked_list(head);
        break;

    case 11:
        exit(1);

    default:
            printf("wrong choice\n");
            break;
    }
}
return 0;
}
Node *create_list(Node *head){
Node *newnode=NULL;//head-have base address of ist node
Node *temp;//as we cant change head ,for traversing
int choice1=1,count=0;
head=NULL;

while(choice1){

newnode= (Node*) malloc(sizeof(Node));
//size of struct node---4+4ptr
//malloc will return a pointer to the starting address of memory block
printf("enter data");
scanf("%d",&newnode->data);//accessing member of a structure
newnode->next=NULL;

if(head==NULL)//ist node
{
//printf("%d->[%p]->",newnode->data,newnode);
  printf("Inside If\n") ;     
head=temp=newnode;//head is having address of newnode
}
else//more than 1 node
{
    printf("\nInside else") ;
    
    temp->next=newnode;
    temp=newnode;

}
printf("do you want to continue\n");
scanf("%d",&choice1);

}
//printing of the linked list
return head;

}
void display(Node *head){
    //head=NULL;
    struct node *temp;
    temp=head;
    if (head==NULL){
    printf("list is empty sorry\n");
    }

    
printf("list is:\n");
//int count=0;
while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
    printf("\t");
  
}
printf("\n");

}
/*function to find the total number of nodes in the linked list
the ll is traversed till null encounters*/
void count(Node *head){
    Node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("the length of the linked list is:%d\n",count);
    count1=count;
    printf("count1:%d\n",count1);
}
/*function to insert the node at the beginning
1st case if it is the ist node
2nd to insert in a already created ll*/
Node *Insertion_at_beg(Node *head){
    Node * newnode;
    newnode=(Node *)malloc(sizeof(Node));
    printf("enter data of your choice for the beginning");
    scanf("%d ",&newnode->data);
    {
        //if no element on the list
        if(head==NULL){
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            /* code */
            newnode->next=head;
            head=newnode;
            
        }
        
    }
}


Node *Insertion_at_end(Node *head)
{
    Node *newnode,*temp;
    newnode=(Node *)malloc(sizeof(Node));
    printf("enter the last element you want to enter\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    temp=head;
}

Node *Insertion_in_a_given_position(Node *head)
{
    printf("count is: %d\n",count1);
    Node *temp,*newnode;
    //int count;
    int pos,i=1;
    printf("enter the position of your choice\n");
    scanf("%d",&pos);
    if(pos>count1){
        printf("invalid position\n");
    }
    else
    {   newnode=(Node *)malloc(sizeof(Node));
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        //temp=head;
        printf("enter the data of your choice\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
        temp=head;
        
    }
    
    
    
}

Node *Deletion_at_beg(Node *head)
{
    Node *temp;
    temp=head;
    if(head==NULL){
        printf("List is Empty\n");
    }
    else
    {   
        
        head=temp->next;
        free(temp);
}
    temp=head;
}

Node *Deletion_at_end(Node *head)
{
    Node *temp,*prevnode;
    temp=head;
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    //if only one node is present
    if(temp==head){
        head=NULL;

    }
    else
    {
        prevnode->next=NULL;
    }
    free(temp);
    temp=head;
    
}

Node *Deletion_at_specified_position(Node *head){

Node *newnode,*temp;
int pos,i=1;
temp=head;
printf("enter the position uh want to delete at\n");
scanf("%d",&pos);
while(i<pos-1)
{
    temp=temp->next;
    i++;
}

newnode=temp->next;
temp->next=newnode->next;
free(newnode);
temp=head;
}

Node *Reversing_the_linked_list(Node *head)
{
    Node *currentnode,*prevnode,*nextnode;
    prevnode=0;//at ist there is no node so pn will hold zero
    currentnode=nextnode=head;//traversing from ist node
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;

    }
    head=prevnode;
    return head;

}
