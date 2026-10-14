#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head = NULL, *temp,*new,*least=NULL;
void add_node();
void add_last();
void add_spe_node();
void delete_start();
void delete_last();
void delete_spe_node();
void display();
void search();
void count();
int main()
{
    int choice = 0;
    do
    {
        printf("\n1. Add node at begin.");
        printf("\n2. Add node at last.");
        printf("\n3. Add at specific location.");
        printf("\n4. Delete from begin.");
        printf("\n5. Delete from last.");
        printf("\n6. Delete from specific location.");
        printf("\n7. Display Linked list.");
        printf("\n8. Search Node.");
        printf("\n9. Count node.");
        printf("\n10. Exit.");
        printf("\n=================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_node();
            break;
        case 2:
            add_last();
            break;
        case 3:
            add_spe_node();
            break;
        case 4:
            delete_start();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_spe_node();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            count();
            break;
        case 10:
            break;
        default:
            printf("Invalid choice: ");
        }
    } while (choice != 10);
    return 0;
}

void add_node()
{
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter your element: ");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        new->left = NULL;
        new->right = NULL;
        head = new;
        least = new;
    }
    else
    {
        new->right = head;
        new->left = NULL;
        head->left = new;
        head = new;
    }
}

void add_last()
{
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter your element: ");
    scanf("%d",&new->data);
    if(least==NULL)
    {
        new->right = NULL;
        new->left = NULL;
        least = new;
        head = new;
    }
    else
    {
        new->left = least;
        new->right = NULL;
        least->right = new;
        least = new;
    }
}

void add_spe_node()
{
    int location = 0;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter your element: ");
    scanf("%d",&new->data);
    printf("Enter the Location: ");
    scanf("%d",&location);
    temp = head;
    for(int i=1; i<location; i++)
    {
        temp = temp->right;
    }
    new -> left = temp;
    new -> right = temp -> right;
    temp -> right = new;
}

void delete_start()
{
    printf("%d is deleted.",head->data);
    temp = head->right;
    free(head);
    head = temp;
}

void delete_last()
{
    printf("%d is deleted.",least->data);
    temp = least->left;
    free(least);
    temp -> right = NULL;
    least = temp;
}

void delete_spe_node()
{
    int location = 0;
    printf("Enter your Node Position: ");
    scanf("%d",&location);
    temp = head;
    for(int i=2; i<location; i++)
    {
        temp = temp->right;
    }
    printf("%d is deleted from Linked list.",temp->data);
    new = temp->right;
    temp->right = new->right;
    new = temp->right;
    new->left = temp;
    free(temp);
}

void display()
{
    temp = head;
    while(temp!=NULL)
    {
        printf("%d    ",temp->data);
        temp = temp->right;
    }
}

void search()
{
    
}

void count()
{


}