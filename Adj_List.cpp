// Adjacency List representation of a graph using pointers in C++ // 


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int no;
	struct node* next;
};

struct rnode
{
	int n;
	struct rnode* down;
	struct node* child;
};

void adjacencylist(struct rnode* root)
{
	struct rnode* froot;
	struct node* fhead;
	int n;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d",&n);
	int i;
	int d;
	int v;
	int j;
	for(i=0;i<n;i++)
	{	
		struct node* head = NULL;
		printf("\nEnter the degree of node number %d : ",i+1);
		scanf("%d",&d);
		printf("Enter the adjacent vertices\n");
		
		for(j=0;j<d;j++)
		{	
			scanf("%d",&v);
			struct node* temp = new node;
			temp->next = NULL;
			temp->no=v;
			if(head == NULL)
			{
				head = temp;
				fhead = head;
			}
			else
			{
				head->next = temp;
				head = temp;
			}
			if(j==0)
			{
				struct rnode* temp1 = new rnode;
				temp1->child = head;
				temp1->down=NULL;
				temp1->n = i+1;
				if(root == NULL)
					{
						root = temp1;
						froot = root;
					}
				else
					{
						root->down = temp1;
						root = temp1;
					}
					
			}
		}
		
	}
	struct rnode* temp1 = froot;
	while(temp1!=NULL)
	{
		struct node* temp = temp1->child;
		while(temp!=NULL)
		{
			printf("The edge from vertex %d to vertex %d has been added... \n",temp1->n, temp->no);
			temp=temp->next;
		}
		temp1=temp1->down;
	}
	
}

int main()
{
	struct rnode* head = NULL;
	adjacencylist(head);
	return 0;
}
