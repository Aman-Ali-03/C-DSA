#include <stdio.h>
#include <stdlib.h>
struct node // Defining a structure of node
{
    int data;          // To store the node element
    struct node *next; // To store the next node address
};
struct node *head = NULL, *least = NULL, *new_node, *temp; // Declaring some variable
void add_beginning();                                      // Declaration Add node atbegin function
void addla();                                              // Declaration Add Node At last function
void delete_start();                                       // Declaration Delete Node at start function
void delete_last();                                        // Declaration Delete node at last function
void add_specific_node();                                  // Declaration Add node at specific location function
void delete_specific_node();                               // Declaration delete specific location function
void display();                                            // Declaration Display function
void count();                                              // Declaration Count function
void search();                                             // Declaration Search function
int main()
{
    int choice = 0; // Declaration variable to store the user choice
    do
    {
        // Display the menu of function for the user and select the function
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n1. Add Node At Begining.");
        printf("\n2. Add Node At Last.");
        printf("\n3. Add Node At Specific Location.");
        printf("\n4. Display Linked list.");
        printf("\n5. Delete Node At Specific Location.");
        printf("\n6. Delete from Begining.");
        printf("\n7. Delete from Last.");
        printf("\n8. Count Number Of Node.");
        printf("\n9. Search Element.");
        printf("\n10. Exit.");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nEnter your chice: ");
        scanf("%d", &choice);
        switch (choice) // Switch for selecting the function asper user choice
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
            break;
        case 8:
            count();
            break;
        case 9:
            search();
            break;
        case 10:
            break;
        default:
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("Invalid Choice Input.");
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        }
    } while (choice != 9); // Condition for loop
    return 0;
}

void add_beginning() // Defination of Add node at beginning
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter your element: ");
    scanf("%d", &new_node->data); // Take the element from the user
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    if (head == NULL) // Checing the head is empty
    {
        new_node->next = NULL; // make the node next location to be null
        head = new_node;       // Store the address of new node to the head
        least = new_node;      // store the address of node to the last
    }
    else
    {
        new_node->next = head; // Store the head mean previous node address to the new node next postion
        head = new_node;       // rewrite the head fuction to store the lastest node
    }
}

void display() // Defination of Display function
{
    if (head == NULL) // Checking the thee head
    {
        printf("Your Linklist done't have any node.");
    }
    else
    {
        printf("===================================================================================\n");
        temp = head;         //  Assign temp head
        while (temp != NULL) // Run until the temp is null
        {
            printf("%d\t", temp->data); // Display the elment of theprary variable store address
            temp = temp->next;          // Assing the address of temperary address node's next node address
        }
        printf("\n==================================================================================\n");
    }
    return;
}

void add_last() // Defination of Add node at last
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    new_node = (struct node *)malloc(sizeof(struct node)); // Declaring the new node
    printf("Enter the element: ");
    scanf("%d", &new_node->data); // Taking the element from the user
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    new_node->next = NULL;  // Assign the next to be null
    least->next = new_node; // Assing the Least next pointer a new node address
    least = new_node;       // Assign the least a new node
}
void delete_start() //  Defination of Deleting node at start
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%d is delete from the begining.", head->data); // Display the element of delete node
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head->next; // Assign the head next pointer to the temp variable
    free(head);        // free the address of head address
    head = temp;       // Assign temp to the head
}

void delete_last() // Defination of delete node at last
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%d is deleted from the last.", least->data); // Display the element of least varable
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head;                                      // Assign head to the temp
    while (temp->next != NULL && temp->next != least) // Run loop until the temp next pointer is null
    {
        temp = temp->next; // Assign the temp next pointer the temp
    }
    temp->next = NULL; // Make the temp next pointer to null
    free(least);       //Free the least address
    least = temp;   // Assign the temp to the least variable
}

void add_specific_location() // Defination of add node at specific location
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    int location = 0;
    new_node = (struct node *)malloc(sizeof(struct node)); // Declaring a new node 
    printf("\nEnter the Element: ");
    scanf("%d", &new_node->data);  // Read a element from the user 
    new_node->next = NULL;   // make a new node next pointer to be null
    printf("\nEnter the location: ");
    scanf("%d", &location);  // Take the position for add node at that position
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head;  // Assign the head to temp
    for (int i = 0; i < (location - 1); i++)  //  run loop the position-1 number of time 
    {
        temp = temp->next;  
    }
    new_node->next = temp;   // make the new node next pointer to be temp 
    temp = head;  //  Assign head to temp
    for (int i = 0; i < (location - 2); i++)  // run loop the position - 2 number of time
    {
        temp = temp->next;
    }
    temp->next = new_node;  // Assign temp next pointer a new node
}

void delete_specific_location() // Defination of delete node at perticular position
{
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    int location = 0;
    printf("Enter Location for Deletion: ");
    scanf("%d", &location); // Take the position of the node
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    temp = head;  // Assign head to temp
    for (int i = 0; i < location; i++)  // Run loop the positio number of time
    {
        temp = temp->next;
    }
    struct node *hold = temp;  // Declaring a hold of type structure
    temp = head;  // Assing head to temp 
    for (int i = 0; i < (location - 2); i++) // Run loop position -2 no. of time
    {
        temp = temp->next;
    }
    temp->next = hold;  // Assing the temp next pointer a hold
}

void count() // Defination of Count node at linked list
{
    int counter = 0;
    temp = head;   // Assing head to temp
    while (temp != NULL)   // Run until the temp is null  
    {
        counter++;     // increment the counter by one on each iteration
        temp = temp->next;   // Assign temp next pointer to the temp
    }
    printf("Linked list have %d Number of nodes.", counter);  // Display the counter 
}

void search() // Defination of Serching node by the element
{
    int counter = -1;
    int find = -1;
    printf("Enter your element: ");
    scanf("%d", &find);   // Get the element to search 
    temp = head;        // Assign head to temp
    while (temp != NULL)     // Run until the temp is null
    {
        counter++;   // Increament the counter 
        if (temp->data == find)    // Checking teh node element is equal to the find elemnt 
        {
            break;
        }
        temp = temp->next;    // Assign temp next pointer to the temp
    }
    if (counter != -1)   
    {
        printf("Element found at Node no. %d.", counter + 1);
    }
    else
    {
        printf("Element not found at the linked list.");
    }
}