#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *pre;
    int data;
    struct node *next;
}node;
void create_doubly_linkedlist(node ** head,node **tail,int n)
{
    node *temp,*ptr;
    ptr = *tail;
    for(int i = 0;i<n;i++){
    ptr = (node*)malloc(sizeof(node));
    printf("Enter a data:- ");
    scanf("%d",&(ptr->data));
    if(*head == NULL)
    {
        *head = *tail = temp = ptr;
        temp ->pre = NULL;
        temp->next = NULL;

    }
    else{
        *tail = ptr;
        temp->next = ptr;
        ptr->pre = temp;
        ptr->next = NULL;
        temp = ptr;
    }
    }
}
void delete_key(node **head,node **last,int key)
{
    node *temp;
    temp = *head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            if (temp->pre == NULL)
            {
                node *ptr;
                ptr = temp;
                *head = temp = ptr->next;
                temp->pre = NULL;
                free(ptr);
                continue;
            }
            if(temp->next == NULL)
            {
                node *ptr;
                ptr = temp;
                temp = ptr->pre;
                *last = temp;
                temp->next = NULL;
                free(ptr);
                continue;
            }
            else{
                node *ptr;
                ptr = temp;
                ptr->next->pre = ptr->pre;
                ptr->pre->next = ptr->next;
                free(ptr);
            }

        }
        temp = temp->next;
    }
}
void display_elements(node *head)
{
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;

    }
    printf("\n");
    
}
void reverse_display(node *last)
{
    while (last != NULL)
    {
        printf("%d ",last->data);
        last = last->pre;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    node *head=NULL,*last=NULL;
    int n,key;
    printf("Enter no. of node:- ");
    scanf("%d",&n);
    create_doubly_linkedlist(&head,&last,n);
    printf("Elements :- ");
    display_elements(head);
    printf("Elements in reverse :- ");
    reverse_display(last);
    printf("Enter a key:- ");
    scanf("%d",&key);
    delete_key(&head,&last,key);
    printf("Elements after deletion are:- ");
    display_elements(head);
    return 0;
}

