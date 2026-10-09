#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*new,*temp;
void add_begin();
void delete();
void display();
void main()
{
    int choice=0;
    do{
        printf("\n========================================");
        printf("\n1. Add Node.");
        printf("\n2. Delete Node.");
        printf("\n3. Display.");
        printf("\n4. Exit.");
        printf("\n========================================");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_begin();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("\n========================================");
                printf("\nInvalid choice.");
                printf("\n========================================");
        }
    }while(choice!=4);
    return;
}

void add_begin()
{
    new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter your element: ");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        new->next = NULL;
        head = new;
    }
    else{
        new->next = head;
        head = new;
    }
    return;
}

void delete()
{
    printf("%d is deleted.",head->data);
    temp = head->next;
    free(head);
    head = temp;
    return;
}

void display()
{
    temp = head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    return;
}