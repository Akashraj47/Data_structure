#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node{
	int data;
	node *left;
	node *right;
};
node* in_oder_successor(node *root)
{
	root =  root->right;
    if(root == NULL)
    {
        return NULL;
    }
    else{
	    while(root->left != NULL){
		    root = root->left;
	    }
    }
	return root;
}
node* in_oder_predecessor(node *root)
{
	root =  root->left;
    if(root == NULL)
    {
        return NULL;
    }
    else{
	    while(root->right != NULL){
		    root = root->right;
	    }
    }
	return root;
}
node* delete(node *root,int num)
{
	if(root->data > num){
		root->left = delete(root->left,num);
	}
	else if(root->data < num){
		delete(root->right,num);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}
		else{
			node *temp1,*temp2;
			temp1 = in_oder_successor(root);
            temp2 = in_oder_predecessor(root);
            if (temp1 == NULL)
            {
                root->data = temp2->data;
			    root->left = delete(root->left,temp2->data);
            }
            else
            {
                root->data = temp1->data;
			    root->right = delete(root->right,temp1->data);
            }
		}
	}
	return root;
}
void search(node *root,int num)
{
	if(root == NULL)
	{
		printf("ELEMENT NOT FOUND\n");
		return;
	}
	if(root->data == num)
	{
		printf("Element found :- %d\n",root->data);
	}
	else{
		if(root->data > num){
			search(root->left,num);
		}
		else{
			search(root->right,num);
		}
	}
}
void insert(node **root,int num)
{
	if(*root == NULL)
	{
		node *ptr ;
		ptr = (node*)malloc(sizeof(node));
		ptr->data = num;
		ptr->left = NULL;
		ptr->right = NULL;
		*root = ptr;
	}
	else{
		if((*root)->data > num){
			insert(&(*root)->left,num);
		}
		else{
			insert(&(*root)->right,num);
		}
	}
}
void display_in_order(node *root)
{
	if(root != NULL){
		display_in_order(root->left);
		printf("%d ",root->data);
		display_in_order(root->right);
	}
}
int main()
{
	node *root = NULL;
	int q = 1,choice=0,num;
	while(q){
		printf("Enter choice\n");
		printf("1.Enter data in bst\n2.Search data\n3.delete node\n4.display\n5.quit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("Enter data to insert\n");
			scanf("%d",&num);
			insert(&root,num);
			break;
			case 2:
			printf("Enter data to search\n");
			scanf("%d",&num);
			search(root,num);
			break;
			case 3:
			printf("Enter a number to delete\n");
			scanf("%d",&num);
			root = delete(root,num);
			break;
			case 4:
      printf("Root node is:- %d\n",root->data);
      printf("Elements are:- ");
			display_in_order(root);
			printf("\n");
			break;
			case 5:
			q = 0;
			break;
			default:
			printf("Invalid input\n");
			}
		}
	return 0;
}
