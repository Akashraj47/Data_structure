#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create_circular_ll(node **head,int n)
{
    node *ptr,*temp;
    for(int i = 0;i<n;i++)
    {
        ptr = (node*)malloc(sizeof(node));
        printf("Enter data:- ");
        scanf("%d",&(ptr->data));
        if (*head == NULL)
        {
            *head = temp = ptr;
            ptr->next = *head;
        }
        else{
            temp->next = ptr;
            temp = ptr;
            temp->next = *head;
        }
        
    }
}
void display(node *head)
{
    node *temp;
    temp = head;
    printf("Elements are:- ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
}
void find_last(node *head,node **last)
{
    node *temp;
    temp = head;
    do{
        if(temp->next == head)
        {
            *last = temp;
        }
        temp = temp->next;
    }while(temp != head);
}
void delete_key_element(node **head,node **tail,int key)
{
    node *ptr,*temp,*last;
    ptr = *head;
    temp = ptr->next;
    do
    {
        if(ptr->data == key)
        {
            node *temp2;
            temp2  = ptr;
            *head = ptr = temp2->next;
            temp = ptr->next;
            last = *tail;
            last->next = *head;
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
    } while (temp != *head);
}
int main(int argc, char const *argv[])
{
    node *head = NULL,*last;
    node *temp,*ptr;
    int key;
    int n;
    printf("Enter the number of node you want to enter\n");
    scanf("%d",&n);
    create_circular_ll(&head,n);
    display(head);
    temp = head;
    find_last(head,&last);
    printf("\nEnter key:- ");
    scanf("%d",&key);
    delete_key_element(&head,&last,key);
    ptr = head;
    temp = ptr ->next;
    temp = head;
    do
    {
        printf("%d ",temp->data);
        temp = temp ->next;
    } while (temp != head);
    
    
   
    
    return 0;
}
