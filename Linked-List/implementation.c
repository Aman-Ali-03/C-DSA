#include <stdio.h> 
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*least=NULL,*new_node;
void addbegining();
void display();
int main(){
    int choice=0;
    do{
        printf("\n1. Add Node At Begining.");
        printf("\n2. Display Linked list.");
        printf("\n++++++++++++++++++++++++++++++++++++");
        printf("\nEnter your chice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addbegining();
                break;
            case 2:
                display();
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
        struct node *temp=head;
        while(head!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}