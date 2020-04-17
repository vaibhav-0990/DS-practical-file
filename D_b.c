#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL,*last=NULL;
node* create_node(int key)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->next=temp->prev=NULL;
    temp->data=key;
    return temp;
}
void insert_front(int key)
{
    if (head==NULL)
    {
        head=last=create_node(key);
    }
    else
    {
        node* temp=create_node(key);
        temp->next=head;
        head->prev=temp;
        head=temp;
    } 
}
void insert_rear(int key)
{
    if (head==NULL)
    {
        head=last=create_node(key);
    }
    else
    {
        node* temp=create_node(key);
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}
void delete_front()
{
    if (head==NULL)
    return;
    printf ("%d\n",head->data);
    node* temp=head;
    head=head->next;
    if (head)
    head->prev=NULL;
    else 
    head=NULL;
    free(temp);
}
void delete_rear()
{
    if (head==NULL)
    return;
    printf ("%d\n",last->data);
    node* temp=last;
    last=last->prev;
    if (last)
    last->next=NULL;
    else 
    head=NULL;
    free(temp);
}
void display()
{
   for (node* temp=head;temp!=NULL;temp=temp->next)
   printf ("%d  ",temp->data);
   printf ("\n");
}
int main()
{
    int y,data;
    printf ("To insert at begining press 1\nTo insert at end press 2\n");
    printf ("To delete at begining press 3\nTo delete at end press 4\n");
    printf ("To display press 5\nTo exit press 0\n");
    scanf("%d",&y);
    while(y)
    {
        if (y==1)
        {
            printf ("Enter data to be inserted\n");
            scanf("%d",&data);
            insert_front(data);
        }
        else if (y==2)
        {
            printf ("Enter data to be inserted\n");
            scanf("%d",&data);
            insert_rear(data);
        }
        else if (y==3)
        {
            delete_front();
        }
        else if (y==4)
        {
            delete_rear();
        }
        else if (y==5)
        {
            display();
        }
        printf ("To insert at begining press 1\nTo insert at end press 2\n");
        printf ("To delete at begining press 3\nTo delete at end press 4\n");
        printf ("To display press 5\nTo exit press 0\n");
        scanf("%d",&y);
    }
}