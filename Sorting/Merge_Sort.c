#include <stdio.h> 

void merge_sort(int [],int,int);
void merge(int [],int,int,int);
int main(){
    int a[5] = {5,4,3,2,1};
    merge_sort(a,0,4);
    for(int i=0; i<5; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
void merge_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);

        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int b[10];
    while(i<=mid+1 && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = b[k];
}