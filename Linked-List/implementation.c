#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *least = NULL, *new_node, *temp;
void addbegining();
void display();
void addla();
void delete_start();
void delete_last();
void add_speci_loc();
void delete_speci_loc();
int main()
{
    int choice = 0;
    do
    {
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n1. Add Node At Begining.");
        printf("\n2. Add Node At Last.");
        printf("\n3. Add Node At Specific Location.");
        printf("\n4. Display Linked list.");
        printf("\n5. Delete Node At Specific Location.");
        printf("\n6. Delete from Begining.");
        printf("\n7. Delete from Last.");
        printf("\n8. Exit.");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nEnter your chice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addbegining();
            break;
        case 2:
            addla();
            break;
        case 3:
            add_speci_loc();
            break;
        case 4:
            display();
            break;
        case 5:
            delete_speci_loc();
            break;
        case 6:
            delete_start();
            break;
        case 7:
            delete_last();
        case 8:
            break;
        default:
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("Invalid Choice Input.");
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        }
    } while (choice != 9);
    return 0;
}

void addbegining()
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter your element: ");
    scanf("%d", &new_node->data);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    if (head == NULL)
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
    if (head == NULL)
    {
        printf("Your Linklist done't have any node.");
    }
    else
    {
        printf("=====================================================================================================================");
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n=====================================================================================================================");
    }
    return;
}

void addla()
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &new_node->data);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    new_node->next = NULL;
    least->next = new_node;
    least = new_node;
}
void delete_start()
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%d is delete from the begining.", head->data);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head->next;
    free(head);
    head = temp;
}

void delete_last()
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%d is deleted from the last.", least->data);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head;
    while (temp->next != NULL && temp->next != least)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(least);
    least = temp;
}

void add_speci_loc()
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    int location = 0;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Element: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    printf("\nEnter the location: ");
    scanf("%d", &location);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head;
    for (int i = 0; i < (location - 1); i++)
    {
        temp = temp->next;
    }
    new_node->next = temp;
    temp = head;
    for (int i = 0; i < (location - 2); i++)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_speci_loc()
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    int location = 0;
    printf("Enter Location for Deletion: ");
    scanf("%d",&location);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head;
    for(int i=0; i<location; i++)
    {
        temp = temp->next;
    }
    struct node *hold = temp;
    temp = head;
    for(int i=0; i<(location-2); i++)
    {
        temp = temp->next;
    }
    temp->next = hold;
}