// Adjacency List for Undirected Graph // 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int nno;
	struct node* next;
};


void addnode(struct node arr[], int d, int n)
{
	struct node* root = &arr[n-1];
	struct node* track;
	int i,j;
	int nodd1;
	for(i=0;i<d;i++)
	{
		printf("\nEnter the neighbour of vertex %d\n",n);
		scanf("%d",&nodd1);   
		if(i==0)
		{
			struct node* temp = new node;
			temp->next = NULL;
			temp->nno = nodd1;
			root->next = temp;
			root->nno = n;
			track = temp;
		}
		else
		{
			struct node* temp = new node;
			temp->next = NULL;
			temp->nno = nodd1;
			track->next = temp;
			track = temp;
		}
	}
}

void display(struct node arr[], int n)
{
	int i = 0;
	while(i<n)
	{
		struct node* temp = &arr[i];
		struct node* track = temp->next;
		while(track!=NULL)
		{
			printf("Edge added from vertex %d to vertex %d \n", temp->nno, track->nno );
			track = track->next;
		}
		i+=1;
	}
}


int main()
{
	int n;
	int d;
	printf("Enter the number of nodes in the graph :\n");
	scanf("%d",&n);
	struct node graph[n];
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter the degree of node %d:\n", i+1);
		scanf("%d",&d);
		addnode(graph,d,i+1);
	}
	display(graph,n);
	return 0;
	
}
