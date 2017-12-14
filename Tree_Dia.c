// C Program that computes the diameter of a tree in O(n) time // 

#include<stdio.h>
#include<stdlib.h>

int dia = 0;
struct node
{
	struct node* left;
	struct node* right;
	int maxv;
	int leftd;
	int rightd;
};

struct node root;

struct node* getnode()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->maxv = -1;
	temp->leftd=0;
	temp->rightd=0;
	return temp;
};

void diameter(struct node* root)
{	
	struct node* v = root;
	if(v->left!=NULL )
		{
			diameter(v->left);
		}	
	if(v->right!=NULL)
		{
			diameter(v->right);
		}
	if(v->left!=NULL && v->right!=NULL)
		{
			v->leftd = v->left->maxv + 1;
			v->rightd = v->right->maxv + 1;
		}
	else if(v->left==NULL && v->right!=NULL)
		{
			v->leftd = 0;
			v->rightd = 1 + v->right->maxv;
		}
	else if(v->right==NULL && v->left!=NULL)
		{
			v->rightd = 0;
			v->leftd = 1+ v->left->maxv;
		}
	else
	{
		v->leftd=0;
		v->rightd=0;
	}
	v->maxv = (v->leftd>v->rightd)?v->leftd:v->rightd;
	dia = (v->leftd + v->rightd+1>dia)?v->leftd + v->rightd:dia;
	printf("The left dia value is : %d and the right dia value is %d\n", v->leftd, v->rightd);
	printf("The diameter is currently %d\n", dia+1);
}

int main()
{
	struct node* root = getnode();
	root->left = getnode();
	root->left->left = getnode();
	root->left->right = getnode();
	root->left->left->left=getnode();
	root->left->left->right = getnode();
	root->left->left->left->left=getnode();
	root->left->left->left->right=getnode();
	root->left->right->left=getnode();
	root->left->right->right=getnode();
	root->left->right->right->left=getnode();
	root->left->right->right->right=getnode();
	root->left->right->right->left->left=getnode();
	root->left->right->right->left->right=getnode();
	diameter(root);
	printf("The diameter of the tree is %d", dia + 1);
	return 0;
}

// This is for a custom tree -- Will update with a very general function for inputting a tree! 


