#include <stdio.h> 

void sort(int []);
int main(){
    int a[10] = {2,3,1,4,5,6,7,8,9,10};
    sort(a);
    for(int i=0; i<10; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}

void sort(int a[])
{
    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<10; j++)
        {
            if(a[i]<a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}