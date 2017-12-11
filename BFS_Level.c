////// C Program - Breadth First Search - Complexity is O(n^2) - Usage of Adjacency Matrix// 



#include<stdio.h>
#include<stdlib.h>

//Some Global Useful Variables...
int visited[20];
int level[20];
int parent[20];


int bfs( int s, int t, int arr[][20], int n);
void printpath(int s, int t)
{
	if(s==t)
	{
		printf(" %d",s);
	}
	else
	{
		if(parent[t]!= -1)
		{
		printpath(s, parent[t]);
		printf(" %d", t);
		}
		else
		{
			printf("No path exists");
		}
}
}


// Queue Functions......
int dequeue();
void enqueue(int a);
int isEmpty();
int isFull();
int queue[20];
int size = 20;
int front=-1;
int rear=-1;
// Queue function declaration ends.....

int main()


{
    int n,i;
    int d;
    int j;
    int l;
    scanf("%d\n", &n);
    int a[20][20];
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        a[i][j] = 0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d\n", &d);
        for( j=0; j<d;j++)
        {
            scanf("%d\n",&l);
            a[i][l-1]=1;
        }

    }
			    int s;
			    int t;
				scanf("%d\n",&s);
			    scanf("%d",&t);
    bfs(s,t,a,n);
    printpath(s,t);
    return 0;
}

 int k=0;
 int j=0;
 int l=0;
bfs( int s, int t, int arr[][20], int n)
{  
	int i;
	for(i=0;i<20;i++)
	{
		visited[i]=-1; // Visited [i] = -1 => White Coloured Vertices, Visited[i] = 0 => Grey Vertices, Visited[i]=1 => Black Vertices
		level[i]=-1;
		parent[i]=-1;
	}
	visited[s]=0;
	enqueue(s);	
	level[s]=0;
	while(!isEmpty())
	{
		int u = dequeue();
		int i;
		for(i=0;i<n;i++)
		{
			if (arr[u-1][i]==1 && visited[i+1]==-1)
			{
				enqueue(i+1);
				level[i+1]=level[u]+1;
				parent[i+1]=u;
				visited[i+1]=0;
			}
		}
		visited[u]=1;
	}
	
	printf("The final updated levels after the BFS Traversals.... \n");
	for(i=0;i<n;i++)
	{	
		printf("Node - %d, Level - %d, Parent - %d \n",i+1, level[i+1],parent[i+1],visited[i+1]);
	}
}
// Queue function definitions

void enqueue(int a)

{
    if (front== -1)
    {
        front  =  0;
        rear = rear + 1;
        queue[front ] = a;
    }
    else if(rear==size-1 && front!=0)
    {     rear = 0;
        queue[rear] = a;

    }
    else
    {
        rear = rear + 1;
        queue[rear] = a;
    }
}

int dequeue()
{	
	int temp=queue[front];
    if(front == rear )
        front = rear = -1;
    else if(front == size-1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
    return temp;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((rear - front) == size -1|| (front - rear) == 1)
    {
        return 1;
    }
    else
        return 0;
}
 

