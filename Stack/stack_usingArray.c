#include<stdio.h>
#include<stdlib.h>
#define N 7

int stack[N];
int top==-1;
void push();
void pop();
void peek();
void display();
void count();
int main(){
    int choice=0,choice1;
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
    scanf("&d",&choice1);

    switch(choice1)
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
    }

    

}
