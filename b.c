#include<stdio.h>
#include<stdlib.h>
struct node 
{
     struct node *prev;
    int data;
    struct node *next;
}*head=NULL;

void create(int x){
    int element;
    struct node *newnode,*temp;
    head=(struct node *)malloc(sizeof(struct node));
    printf("Enter data to first node:\n");
    scanf("%d",&element);
    head->prev=NULL;
    head->data=element;
    head->next=NULL;
    temp=head;
    for(int i=2;i<=x;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data to %d node:\n",i);
        scanf("%d",&element);
        newnode->data=element;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
        temp=temp->next;
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void delete( struct node *p,int x)
{
    if(x==1)
    {
        head=head->next;
        if(head)
            head->prev=NULL;
        free(p);
    }
    else{
        for(int i=0;i<x-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        int x=p->data;
        free(p);
    }
}
int main()
{
    int n,index;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    create(n);
    display();
    printf("\nEnter the node to delete:\n");
    scanf("%d",&index);
    delete(head,index);
    display();
}