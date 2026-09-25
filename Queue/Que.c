#include <stdio.h> 
int a[10],f=-1,r=-1;
void insert();
void delete();
void display();
int main(){
    int choice;
    do{
        printf("=================================\n");
        printf("1. Insert in Queue.\n");
        printf("2. Delete in Queue.\n");
        printf("3. Display Queue.\n");
        printf("4. Exit.\n");
        printf("=================================\n");
        printf("Enter your chice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
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
                printf("Invalid choice. ");
        }
    }while(choice!=4);
    return 0;
}
void insert()
{
    if(r==9)
    {
        printf("=================================\n");
        printf("Queus is full.\n");
        printf("=================================\n");
        return;
    }
    else{
        if(f==-1)
        {
            f=0;
        }
        r = r + 1;
        printf("=================================\n");
        printf("Enter the element :");
        scanf("%d",&a[r]);
        printf("\n=================================\n");
    }
}
void delete()
{
    if(f==-1)
    {
        printf("=================================\n");
        printf("Queue is empty.\n");
        printf("=================================\n");
        return;
    }
    else
    {
        printf("=================================\n");
        printf("Deleted element is %d",a[f]);
        printf("\n=================================\n");
        f = f+1;
    }
}
void display()
{
    if(f==-1)
    {
        printf("=================================\n");
        printf("Queue is empty.\n");
        printf("=================================\n");
        return;
    }
    else
    {
        printf("=================================\n");
        printf("             Element             \n");
        printf("=================================\n");
        for(int i=f; i<=r; i++)
        {
            printf("%d",a[i]);
            printf("\n");
        }
        printf("=================================\n");
    }
}