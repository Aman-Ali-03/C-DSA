#include<stdio.h>
int a[10];
int top=-1;
void push();
void pop();
void display();
int main()
{
    int n;
    do{
        printf("=====================================\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        if(n==1)
            push();
        else if(n==2)
            pop();
        else if(n==3)
            display();
        else{ 
            printf("=====================================\n");
            printf("Invalid Choice.");
            printf("\n=====================================\n");
        }
    }while(n!=4);
}
void push()
{
    if(top>=9)
    {
        printf("=====================================\n");
        printf("Stack is full.\n");
        printf("\n=====================================\n");
        return;
    }
    else{
        top++;
        printf("=====================================\n");
        printf("Enter your element: ");
        scanf("%d",&a[top]);
        printf("\n=====================================\n");
    }
}
void pop()
{
    if(top<0)
    {
        printf("=====================================\n");
        printf("Stack is empty.");
        printf("\n=====================================\n");
        return;
    }
    top--;
}
void display()
{
    if(top<0)
    {
        printf("=====================================\n\n");
        printf("Stack is empty.");
        printf("\n=====================================\n");
        return;
    }
    printf("=====================================\n");
    printf("               STACK                 \n");
    printf("=====================================\n");
    for(int i=0; i<=top; i++)
    {
        printf("%d\n",a[i]);
    }
    printf("\n=====================================\n");
}