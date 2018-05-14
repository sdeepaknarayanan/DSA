#include<stdio.h>
#include<stdlib.h>
#define size 20
struct heap
{
	int data;
	int u;
	int v;
};

struct tree
{
	int a;
	int b;
};

struct tree arr[size];
struct heap array[size];
int heapsize ;

void Init()
{
	heapsize = 0;
	array[0].data = -INT_MAX;	
}

void insert(int a, int i, int j)
{
	heapsize++;
	array[heapsize].data = a;
	array[heapsize].u = i;
	array[heapsize].v = j;
	int pos;
	pos = heapsize;
	while ( array[pos/2].data > a)
	{
		array[pos] = array[pos/2];
		pos = pos/2;
	}
	array[pos].data = a;
	array[pos].u = i;
	array[pos].v = j;
}

struct heap deletemin()
{
	struct heap min;
	int  last, child, pos;
	min = array[1];
	last = array[heapsize--].data;
	for( pos = 1; pos *2<=heapsize; pos = child)
	{
		child = pos*2;
		if ( child!=heapsize && array[child+1].data<array[child].data)
		{
			child = child + 1;
		}
		if(last > array[child].data)
		{
			array[pos].data = array[child].data;
			array[pos].u = array[child].u;
			array[pos].v = array[child].v;
 		}
		else
		{
			break;
		}
	}
	array[pos].data  = last;
	return min;
	
}

void mst(int a[][20], int b[][20] , int n, int visited[])
{	
	struct heap temp;
	visited[0] = 1;
	int i = 0;
	int count = 1;
	int j;
	int l = 0;
	for(j=0;j<n;j++)
	{
		if (a[i][j])
		{
			insert(b[i][j],i,j);
		
		}
	}
	while(count<n)
	{
		temp = deletemin();
	
		int i1 = temp.u;
		int i2 = temp.v;
	
		if(visited[i2]==0)
		{	
			visited[i2] = 1;
			arr[l].a = i1;
			arr[l].b = i2;
			l++;		
		
		count+=1;
		
		int t;
		for(t = 0; t<n; t++)
		{
			if(a[i2][t] && !visited[t])
			{
				insert(b[i2][t],i2,t );
			}
			
		}
		visited[i2] = 1;
		}
		
	}
	
	
}


void main()
{	Init();
	int n;
	scanf("%d",&n);
	int d;
	int i;
	int j;
	int a[n][20];
	int b[n][20];
	int set1[n];
	for(i=0;i<n;i++)
	{	set1[i] = 0;
		for(j=0;j<n;j++)
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	int itno;
	int count;
	int l;
	int temp;
	for(i=0;i<n;i++)
	{
		scanf("%d",&d);
		itno = 2 * d;
		for(j=0;j<itno;j++ )
		{
			scanf("%d",&l);
			if(j%2==0)
			{
				a[l][i] = 1;
				temp = l;
			}
			else
			{
				b[temp][i] = l;
			}
		}
	}
	mst(a,b,n,set1);
	for(i=0;i<n-1;i++)
	{
		printf("(%d,%d)", arr[i].a, arr[i].b);
	}

}
