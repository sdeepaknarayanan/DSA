#include<stdio.h>
#include<stdlib.h>

int pow1(int a)
{
int i=0;
int c = 1;
for(i=0;i<a;i++)
{	c = c*10;
}
return c;
}

void radixsort( int arr[], int front, int n, int d);
void bucketsort( int arr[], int front, int n,  int d)
{   
    int c = pow1(d-1);
    int b[n][10];
    int i;
    int j;
    int k = 0;
    for ( i=0; i<n; i++)
    {
        for(j=0;j<10;j++)
        {
            b[i][j] = 0;
        }
    }


    for ( i = front; i<n; i++)
    {
         j = (arr[i]/c)%10;
         if(j!=0)    
             {	
                if(b[0][j]==0)
                {
                    b[0][j] = arr[i];
                }
            
                else 
                {    int l=0;
                     while(b[l][j]!=0)
                    {
                        l = l+1;
                    }
                    b[l][j] = arr[i];
                }
            }
        else
        {
            b[k][0] = arr[i];
            k++;
        }
    }

    j = 0;
    k=front;
    i=0;
while( i <n && j<10 )
    { 
        
        if(b[i][j]!=0)
            {
            arr[k++] = b[i][j];
            i=i+1;
            }
        else
                {
                    j=j+1;
                    i=0;
                }
    }
}


int m;

int main()
{	
	int n; int i;
	char c[20][100];
	scanf("%d\n",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
	gets(c[i]);
	arr[i] = atoi(c[i]);
	}

	m = n;		

	radixsort(arr, 0, n, 5);	
}

void radixsort( int arr[], int front, int n, int d)
{


if(n-front>=0 && d>=0)



{	int i;
	bucketsort(arr, front, n, d);
	for(i=0; i<m; i++)
	printf(" %d",arr[i]);
	printf("\n");
	int k = (arr[front]/pow1(d-1))%10;
	int front1 = front;
	int rear1 = front;
	while(rear1<n )
	{
		
                if(arr[rear1]/(pow1(d-1))== k)
                {
                    rear1+=1;
                }
                else
                {	
                    radixsort(arr,front1,rear1,d-1);
                    front1 = rear1;
                    k = (arr[front1]/pow1(d-1))%10;
                    rear1+=1;
                }
		if(rear1==n)
		{
			radixsort(arr,front1,rear1,d-1);
			front1 = rear1;
                   	k = (arr[front1]/pow1(d-1))%10;
                    	rear1+=1;
                }

            }

}
}
