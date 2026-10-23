#include <stdio.h> 

void Bubble(int [],int);
int main(){
    int a[10],number;
    printf("How many element you want to enter(max 10): ");
    scanf("%d",&number);
    printf("Enter your element: \n");
    for(int i=0; i<number; i++)
    {
        scanf("%d",&a[i]);
    }
    Bubble(a,number);
    printf("Shorted data :\n");
    for(int i=0; i<number; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}

void Bubble(int a[],int num)
{
    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<(num-i-1); j++)
        {
            if(a[j]<a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}