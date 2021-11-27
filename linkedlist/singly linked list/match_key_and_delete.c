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
    while(head != NULL)
    {
        printf("%d ",(head->data));
        head = head->next;
    }
    printf("\n");
}
int delete_node(node **head,int key)
{
    int flag = 0;
    node *ptr,*temp;
    ptr = *head;
    temp = ptr->next;
    while(ptr != NULL)
    {
        if(temp == NULL)
        {
            break;
        }
        if(ptr->data == key)
        {
            flag = 1;
            node* temp2;
            temp2 = ptr;
            *head = ptr = temp2->next;
            temp = ptr->next;
            free(temp2);
            continue;
        }
        if(temp->data == key)
        {
            if(temp->next == NULL)
            {
                flag = 1;
                node *temp2;
                temp2 = temp;
                ptr->next = NULL;
                free(temp);
                break;
            }
            else
            {
                flag = 1;
                node *temp2;
                temp2 = temp;
                ptr->next = temp2->next;
                temp = ptr->next;
                free(temp2);
                continue;
            }
        }
        ptr = ptr->next;
        temp = ptr->next;
    }
    return flag ;
}
int main()
{
    int flag ;
    node *head = NULL;
    int n,key;
    printf("Enter total number of node you want to enter\n");
    scanf("%d",&n);
    creat_node(&head,n);
    printf("elements in the linked list are:- ");
    display(head);
    printf("Enter a key to search and delete:- ");
    scanf("%d",&key);
    flag = delete_node(&head,key);
    if(flag == 1){
    printf("Elements after deletion are:- ");
    display(head);
    }
    else
    {
        printf("Key is not found\n");
    }
    return 0;
}
