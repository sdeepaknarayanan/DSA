// Depth First Search on a directed graph. We will find number of forward edges, number of back edges and number of cross edges, rest all, as we know belongs to the DFS Tree itself // O(n^2) using Adjacency Matrix Representation
// Returns if DAG too :)
#include<stdio.h>
#include<stdlib.h>


int graph[20][20];		// Initialisation of Graph G

int arrivaltime[20];	// Arrival and Departure Times
int departrtime[20];
int visited[20];
int parent[20];
int dag = 1;



int time = 0;

void dfsvisit(int g[][20], int root, int n)
{
	visited[root-1] = 1;
	time = time + 1;
	arrivaltime[root - 1] = time;
	int i;
	for(i=0;i<n;i++)
	{
		if(g[root-1][i] == 1)
		{
			if(visited[i] == -1)
			{
				parent[i+1] = root;
				dfsvisit(g,i+1,n);
			}

		}
	}
	time = time+1;
	departrtime[root-1] = time;
}

void dfs(int g[][20], int n)
{
	int i;
	for(i=0;i<20;i++)
	{
		visited[i] = -1;
		parent[i] = -1;
	}
	for(i=0;i<n;i++)
	{
		if(visited[i] == -1)
		{
			dfsvisit(g,i+1,n);
		}
	}
}

void edgetype(int g[][20], int n)
{
	int i;
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0; j<n; j++)
		{
			if (g[i][j] == 1)
			{
				if (arrivaltime[i] > arrivaltime[j] && departrtime[i] < departrtime[j] )
				{
					printf("There is a backedge from vertex %d to %d\n", i+1, j+1);
					dag = 0;
				}	
				else if(arrivaltime[i] > arrivaltime[j] && departrtime[i] > departrtime[j] )
				{
					printf("There is a cross edge from vertex %d to vertex %d\n", i+1, j+1);	
				}
				else if(arrivaltime[i] < arrivaltime[j] && departrtime[j] < departrtime[i] && parent[j+1]
				!=i+1)
				{
					printf("There is a forward edge from verted %d to vertex %d\n", i+1, j+1);
				}
				else
				{	
					printf("Boring stuff - Regular Tree Edge from vertex %d to vertex %d\n",i+1, j+1);
				} 
			}
		}
	}
}


int main()
{
	
	int i,n,d,j,temp;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			graph[i][j] = 0;
		}
	}
	printf("Enter the number of vertices in the Graph\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("Enter the degree of Vertex No. %d\n", i+1);
		scanf("%d",&d);
			printf("Enter the neighbours of the above vertex\n", i+1 );
			for(j=0;j<d;j++)
			{
				scanf("%d",&temp);
				graph[i][temp-1] = 1;
			}
	}
	dfs(graph,n);
	for(i=0;i<n;i++)
	{
		printf("The arrivals and departures for the node %d are the following : 1. Arrival Time %d, and 2. Depareture Time %d\n",i+1, arrivaltime[i], departrtime[i] );
	}
	edgetype(graph,n);
	if(dag)
	{
		printf("This is a beautiful graph - It's a DAG! Topo Sort can be done\n");
	}
	else
	{
		printf("The existence of backedge says it all - Not a DAG :(\n");
	}
}




