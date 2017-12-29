// Making a Binary Search Tree of a sorted array //  Also with insert and delete functionality! // Time complexity - O(h) - Height of the tree 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};


void inorder(struct node* root) // Inorder Traversal 
{
	if(root->left!=NULL)
	{
		inorder(root->left);
	}
	
	printf("\nThe value is %d\n",root->data);
	
	if(root->right!=NULL)
	{
		inorder(root->right);
	}
}

struct node* makebst(int a[],int start, int end) // BST from a sorted array //
{
	if(start == end)
	{
		return NULL;
	}
	
	else
	{
		int mid = (start + end)/2;
		struct node* temp = new node;
		temp->data = a[mid];
		temp->left =  makebst(  a, start, mid);
		temp->right = makebst(a,mid+1,end);
		return temp;
	}
	
}

void insertbst( struct node* root, int a)		// Insertion into a Binary Search Tree in O(h) time -- Assume all elements are distinct -- h - height of the tree -- Already values exist//
{
	struct node* temp = root;
	int flag;
	while(1)
	{
		if(temp->data > a)
		{
			flag = 0;
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else 
			{
				break;
			}
		}
		else if(temp->data < a)
		{
			flag = 1;
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else
			{
				break;
			}
		}
	
	}
	if(flag)
	{
		struct node* addnode = new node;
		addnode->data = a;
		addnode->left = addnode->right = NULL;
		temp->right = addnode;
	}
	else
	{	
		struct node* addnode = new node;
		addnode->data = a;
		addnode->left = addnode->right = NULL;
		temp->left = addnode;
	}
		

}

void deletenode( struct node* root, int a) // Very similar to search //  Assume that there are already a few elements in the BST
{
	struct node* temp = root;
	struct node* prev1 = root;
	int lr;
	while(1)
	{
		if(a>temp->data)
		{
			prev1 = temp;
			temp=temp->right;
			lr = 1;
			printf("\nGoing right\n");
		}
		else if(a<temp->data)
		{
			prev1 = temp;
			temp=temp->left;
			lr = 0;
			printf("\nGoing Left\n");
		}
		else
		{
			printf("\nEntered the deletion phase\n");
			if(temp->left== NULL && temp->right == NULL)
			{
				printf("\nEncountered case 1.....\n");
				if(lr)
				{
					prev1->right = NULL;
				}
				else
				{
					prev1->left  = NULL;
				}
				temp = NULL;
				delete temp;
			}
			
			else if(temp->left!=NULL)
			{	
				int flag1 = 1;
				if(temp->left->left!=NULL && temp->left->right == NULL)
				{
					flag1 = 0;
				}
				if(flag1)
				{
					printf("\n Encountered case 2 ....\n");
					int flag = 0;
					struct node* temp1 = temp->left;
					struct node* previous = temp;
					while(temp1->right!=NULL)
					{
						previous = temp1;
						temp1 = temp1->right;
						flag = 1;
					}
					temp->data = temp1->data;
					if(flag)
					{
						previous->right = NULL;
					}
					else
					{
						temp->left = NULL;
					}
					delete(temp1);
					}	
				else
				{
					temp->data = temp->left->data;
					temp->left = temp->left->left;
					struct node* temp1 = temp->left;
					temp1=NULL;
					delete temp1;
				}
			}
		
			else
			{
				printf("\nEncountered case 3 ....\n");
				temp->data = temp->right->data;
				temp->right = temp->right->right;
				struct node* temp1 = temp->right;
				delete(temp1);			
			}
			break;
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int a[n];
	struct node* root;
	int i;
	printf("\nEnter the elements in sorted order to construct BST\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	root = makebst(a,0,n);
	inorder(root);
	printf("\nEnter the element to be inserted. After insertion the In-Order Traversal will be printed... \n");
	int elem;
	scanf(" %d",&elem);
	insertbst(root,elem);
	inorder(root);
	printf("\nEnter the element to be deleted. After deletion the In-Order Traversal will be printed... \n");
	scanf(" %d",&elem);
	deletenode(root,elem);
	inorder(root);
	return 0;
}

