#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
void insert_node(node **temp,int data)
{
    if(*temp == NULL)
    {
        node *ptr;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        *temp = ptr;
    }
    else
    {
        if((*temp)->data > data)
        {
            insert_node(&((*temp)->left),data);
        }
        else
        {
            insert_node(&((*temp)->right),data);
        }
    }
}
  void display_in(node *root)
  {
      if(root != NULL)
      {
          display_in(root->left);
          printf("%d ",root->data);
          display_in(root->right);
      }
  }
void display_pre(node *root)
  {
      if(root != NULL)
      {
          printf("%d ",root->data);
          display_pre(root->left);
          display_pre(root->right);
      }
  }
  void display_post(node *root)
  {
      if(root != NULL)
      {
          display_pre(root->left);
          display_pre(root->right);
          printf("%d ",root->data);
      }
  }
  int main()
  {
      node *root = NULL;
      insert_node(&root,16);
      insert_node(&root,20);
      insert_node(&root,1);
      insert_node(&root,60);
      insert_node(&root,24);
      insert_node(&root,22);
      insert_node(&root,52);
      display_in(root);
      printf("\n");
      display_pre(root);
      printf("\n");
      display_post(root);
      return 0;
  }
