# include <stdio.h>
int a[10],f=-1,r=-1;
void insert();
void delete();
void display();
int main()
{
    int choice=0;
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
                printf("Invalid choice.\n");
        }
    }while(choice!=4);
    return 0;
}
void insert()
{
    if(((f==0)&&(r==9)) || f==(r+1))
    {
        printf("===================================\n");
        printf("Queue Overflow.\n");
        printf("===================================\n");
    }
    else
    {
        if(f==-1)
        {
            f=0;
        }
        if(r==9&&f!=0)
        {
            r=0;
        }
        else
            r = r + 1;
        printf("===================================\n");
        printf("Enter element: ");
        scanf("%d",&a[r]);
        printf("\n===================================\n");
    }
}
void delete()
{
    if(f==-1)
    {
        printf("===================================\n");
        printf("Queue empty.\n");
        printf("===================================\n");
    }
    else{
        printf("===================================\n");
        printf("Deleted element: %d\n", a[f]);
        printf("===================================\n");
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else{
            f = f+1;
        }
    }
}
void display()
{
    if(f==-1)
    {
        printf("===================================\n");
        printf("Queue empty.\n");
        printf("===================================\n");
    }
    else{
        printf("===================================\n");
        printf("               Element             \n");
        if(f<=r)
        {
            for(int i=f; i<=r; i++)
            {
                printf("%d",a[i]);
                printf("\n");
            }
        }
        else if(f>r)
        {
            for(int i=f; i<=9; i++)
            {
                printf("%d",a[i]);
                printf("\n");
            }
            for(int i=0; i<=r; i++)
            {
                printf("%d",a[i]);
                printf("\n");
            }
        }
        printf("===================================\n");
    }
}