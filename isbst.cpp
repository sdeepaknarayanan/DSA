#include <bits/stdc++.h>

using namespace std;
int ind;
int arr1[100];
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int val)
{
	struct node* temp = new node;
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(struct node* root) // Preorder Traversal 
{
	arr1[ind] = root->data;
	ind++;
	if(root->left!=NULL)
	{
		preorder(root->left);
	}
	
	
	
	if(root->right!=NULL)
	{
		preorder(root->right);
	}
}


struct node* insertbst(struct node* root, int val)
{
	if (root == NULL)
	{
		struct node* temp1 =  newnode(val);
		return temp1;
	}
	if(val<root->data)
	{
		root->left = insertbst(root->left, val);
	}
	else if (val>root->data)
	{
		root->right = insertbst(root->right, val);
	}
	return root;
}

int main()
{
	int t1;
	scanf("%d",&t1);
	int n; 
	int i;

	for(i = 0; i<t1; i++)
	{
		int flag = -1;
		ind = 0;
		scanf("%d", &n);
		int arr[n];
		struct node* root = NULL;
		for(int j =0; j<n;j++)
		{
			scanf("%d",&arr[j]);
			if(j==0)
			{
				root = insertbst(root,arr[j]);
			}
			else
			{
				insertbst(root,arr[j]);
			}
		}
		preorder(root);
		for(int j=0;j<n;j++)
		{
			if(arr[j] == arr1[j])
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if(!flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		
		
	}
	return 0;
}
