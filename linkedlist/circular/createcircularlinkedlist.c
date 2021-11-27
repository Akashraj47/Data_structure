#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
int main(int argc, char const *argv[])
{
    node *head = NULL;
    node *temp;
    int n;
    printf("Enter the number of node you want to enter\n");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        node *ptr;
        ptr = (node*)malloc(sizeof(node));
        printf("Enter data:- ");
        scanf("%d",&(ptr->data));
        if (head == NULL)
        {
            head = temp = ptr;
            ptr->next = head;
        }
        else{
            temp->next = ptr;
            temp = ptr;
            temp->next = head;
        }
        
    }
    temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
    
    return 0;
}
