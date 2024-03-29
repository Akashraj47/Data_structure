#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void creat_node(node **head,int n)
{
    node *temp,*ptr;
    for(int i = 0;i<n;i++)
    {
        ptr = (node*)malloc(sizeof(node));
        printf("Enter data:- ");
        scanf("%d",&(ptr->data));
        if(*head == NULL)
        {
            *head = temp = ptr;
            temp->next = NULL;
        }
        else
        {
            temp->next = ptr;
            temp = ptr;
            temp->next = NULL;
        }
    }
}
void display(node *head)
{
    if(head == NULL)
    {
        printf("List is empty");
    }
    else{
    printf("Elements are :- ");
    while(head != NULL)
    {
        printf("%d ",(head->data));
        head = head->next;
    }
    printf("\n");
    }
}
void delete_node(node **head,int key)
{
    node *ptr,*temp;
    ptr = *head;
    temp = ptr->next;
    
    while(ptr != NULL)
    {
        if(temp == NULL)
        {
            if(ptr->data == key)
            {
                node *temp2;
                temp2 = ptr;
                *head = ptr = temp2->next;
                free(temp2);
            }
            break;
        }
        if(ptr->data == key)
        {
            node* temp2;
            temp2 = ptr;
            *head = ptr = temp2->next;
            temp = ptr->next;
            free(temp2);
            continue;
        }
        if(temp->data == key)
        {
            node *temp2;
            temp2 = temp;
            ptr->next = temp2->next;
            temp = ptr->next;
            free(temp2);
            continue;
        }
        ptr = ptr->next;
        temp = ptr->next;
    }
}
int main()
{
    node *head = NULL;
    int n,key;
    printf("Enter total number of node you want to enter\n");
    scanf("%d",&n);
    creat_node(&head,n);
    display(head);
    printf("Enter a key to search and delete:- ");
    scanf("%d",&key);
    delete_node(&head,key);
    display(head);
    return 0;
}
