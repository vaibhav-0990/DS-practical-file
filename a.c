/*C program which uses functions to create a singly linked list, delete a given integer from the above linked list
 and display the contents after deletion from the above linked list  --Vaibhav Bhaskar IT 11912060*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head=NULL;
void display(){               /* the display function to display the linked list*/
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
}
void create(int n){                /*function to create the linked list*/
    int element;
    struct node *newnode, *temp;
    printf("Enter the data to first node:\n");
    scanf("%d",&element);
    head=(struct node *)malloc(sizeof(struct node));
    head->data=element;
    head->link=NULL;
    temp=head;
    for(int i=2;i<=n;i++)
    {
        printf("Enter the data to %d node:\n",i);
        scanf("%d",&element);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=element;
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
    }
    printf("List created succefully.\n");
}
void delete_node(int integer)             //integer is the which is to be deleted.
{
    struct node *temp=head,*p=NULL;
    if(integer==(head->data)){
        head=head->link;
    }
    struct node *k=head;
    while((k->data)!=integer){     // p is the tail pointer which will follow temp
        p=k;                      //so that temp will point to the node to be deleted,  
        k=k->link;                //and p will point to the previous node so as to change the links.
    }
    p->link=k->link;              // here link is changed, the previous node is pointing to the next node 
    int x=p->data;                // of the one which is to be deleted.
    free(k);                      //free the memory location or the deletion of node.
    printf("node deleted succefully.\n");
}
int main()
{
    int n,integer;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    create(n);
    display();
    printf("\n");
    printf("node to delete:\n");     //getting the data to delete the respective node containing
    scanf("%d",&integer);            //that data.
    delete_node(integer);
    display();
    return 0;
}