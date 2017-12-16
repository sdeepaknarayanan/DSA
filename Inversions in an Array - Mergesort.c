#include<stdio.h>
#include<stdlib.h>
int merge(int arr[], int temp[], int beg, int mid, int end);
int mergesort(int arr[], int temp[], int beg, int end );
void main()
{
int i;
    int n;
    int a[20];
    char c[20][100];
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        gets(c[i]);
        a[i] = atoi(c[i]);
    }
    int o;
    int temp[n];
    for(i=0;i<n;i++)
       {
        temp[i] = a[i];
       }


    o = mergesort(a,temp,0,n-1);
    printf("%d",o);
}

int merge(int arr[], int temp[], int beg, int mid, int end)
{
    int c = beg;
    int c1 = beg;
    int c2 = mid;
    int count = 0;
    while(c1<=mid-1 && c2<=end)
    {
        if(arr[c1] <= arr[c2])
            {
                temp[c]=arr[c1];
                c++; c1++;
            }
        else
        {
            temp[c] = arr[c2];
            c++;
            c2++;
            count+= mid - c1;
        }
    }
        while(c1<= mid-1)
        {
            temp[c] = arr[c1];
            c++;
            c1++;
        }
        while(c2<=end)
        {
            temp[c] = arr[c2];
            c++;
            c2++;
        }
        int i;
        for(i=beg;i<=end;i++)
        {
            arr[i] = temp[i];
        }
        return count;
}

int mergesort(int arr[], int temp[], int beg, int end)
{
    int count = 0;
    if(end>beg)
    {
        int mid = ( beg + end)/2;
        count+=mergesort(arr,temp,beg,mid);
        count+=mergesort(arr,temp,mid+1,end);
        count+=merge(arr,temp,beg,mid+1,end);
    }
    return count;
}
