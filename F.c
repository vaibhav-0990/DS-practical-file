#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;
node* create()
{
    int y;
    printf ("Enter data else -1");
    scanf("%d",&y);
    if (y==-1)
    return NULL;
    node* temp=(node*)malloc(sizeof(node));
    temp->rchild=temp->lchild=NULL;
    temp->data=y;
    printf ("To add left child of %d press 1 else -1",temp->data);
    scanf("%d",&y);
    if (y==1)
    temp->lchild=create();
    printf ("To add right child of %d press 1 else -1",temp->data);
    scanf("%d",&y);
    if (y==1)
    temp->rchild=create();
    return temp;
}
int nodes(node* root)
{
    if (!root)return 0;
    return 1+nodes(root->lchild)+nodes(root->rchild);
}
int main()
{
    node* root=create();//creation of binary tree..........(a)
    
    printf ("No. of nodes\n%d",nodes(root));
}