#include<stdio.h>
#include<stdlib.h>



int partition(int arr[], int front, int end,int len)
{

    int pivot = arr[front];
    int c1 = front + 1;
    int c2 = end;
    while(1)
    {
        while(arr[c1]<pivot && c1<=c2)
        {
            c1=c1+1;
        }
        while(arr[c2]>pivot && c1<=c2)
        {
            c2 = c2 - 1;
        }
        if(c1>c2)
            break;
        else
        {
            int temp = arr[c1];
            arr[c1] = arr[c2];
            arr[c2] = temp;
            c1 = c1 + 1;
            c2 = c2 - 1;
            int beg;
            for(beg= 0;beg<len+1;beg++)
            {
                printf("%d ",arr[beg]);
            }
            printf("\n");
        }
    }
   int temp = arr[front];
    arr[front] = arr[c2];
    arr[c2] = temp;
    int beg;
    for(beg= 0;beg<len+1;beg++)
    {
        printf("%d ",arr[beg]);
    }
    printf("\n");
    return c2;

}

void quicksort(int arr[], int front, int end,int len)
{
    if ((end - front)>=1)
    {
        int i = partition(arr,front,end,len);
        quicksort(arr,front,i,len);
        quicksort(arr,i+1,end,len);
    }




}

int main()
{
    int n;
    int i;
    char c[20][100];
    scanf("%d\n",&n);
    int a[n];
    for (i=0;i<n;i++)
    {
        gets(c[i]);
        a[i] = atoi(c[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1,n-1);
    return 0;
}
