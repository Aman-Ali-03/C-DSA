#include <stdio.h> 
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*least=NULL,*new_node,*temp;
void addbegining();
void display();
void addla();
void delete_start();
void delete_last();
int main(){
    int choice=0;
    do{
        printf("\n++++++++++++++++++++++++++++++++++++");
        printf("\n1. Add Node At Begining.");
        printf("\n2. Display Linked list.");
        printf("\n3. Display Linked list.");
        printf("\n4. Delete from Begining.");
        printf("\n5. Delete from Last.");
        printf("\n++++++++++++++++++++++++++++++++++++");
        printf("\nEnter your chice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addbegining();
                break;
            case 2:
                addla();
                break;
            case 3:
                display();
                break;
            case 4:
                delete_start();
                break;
            case 5:
                delete_last();
                break;
            case 9:
                break;
            default:
                printf("Invalid Choice Input.");
        }
    }while(choice!=9);
    return 0;
}

void addbegining()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter your element: ");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        new_node->next = NULL;
        head = new_node;
        least = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void display()
{
    if(head==NULL){
        printf("Your Linklist done't have any node.");
    }
    else{
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
    return;
}

void addla()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    least->next = new_node;
    least=new_node;
}
void delete_start()
{
    printf("%d is delete from the begining.",head->data);
    temp = head->next;
    free(head);
    head=temp;
}

void delete_last()
{
    printf("%d is deleted from the last.",least->data);
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(least);
    least = temp;
}