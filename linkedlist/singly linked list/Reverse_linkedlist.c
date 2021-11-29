#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create_ll(node **head,int n)
{
    node *temp , *ptr;
    for(int i = 0;i<n;i++)
    {
        ptr = (node*)malloc(sizeof(node));
        printf("Enter data:- ");
        scanf("%d",&(ptr->data));
        if (*head == NULL)
        {
            *head = temp = ptr;
            ptr->next = NULL;
        }
        else{
            temp->next = ptr;
            temp = ptr;
            temp->next = NULL;
        }
        
    }
}
void reverse_ll(node **head,int n)
{
    node *temp,*ptr,*head2;
    if (n == 2)
    {
        temp = *head;
        head2 = *head;
        head2 = head2->next;
        *head = head2;
        temp->next = NULL;
        head2->next = temp;
    }
    if(n > 2){
    temp = *head;
    *head = temp->next;
    head2 = *head;
    ptr = head2->next;
    int count = 0;
    while (ptr != NULL)
    {
        if(count == 0)
        {
            temp ->next = NULL;
            count++;
        }
        head2->next = temp;
        temp = *head;
        *head = ptr;
        head2 = *head;
        ptr = ptr->next;
        if(ptr == NULL)
        {
            head2->next = temp;
            *head = head2;
        }
    }
    }

}
void display(node *head)
{
    while(head != NULL){
    printf("%d ",head->data);
    head = head->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    node *temp,*ptr;
    int n;
    printf("Enter the number of node you want to enter\n");
    scanf("%d",&n);
    create_ll(&head,n);
    printf("Elements before reverse:- ");
    display(head);
    reverse_ll(&head,n);
    printf("Elements after reverse:- ");
    display(head);
    return 0;
}
