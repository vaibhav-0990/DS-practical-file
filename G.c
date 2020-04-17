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
    printf ("Enter data else -1\n");
    scanf("%d",&y);
    if (y==-1)
    return NULL;
    node* temp=(node*)malloc(sizeof(node));
    temp->rchild=temp->lchild=NULL;
    temp->data=y;
    printf ("To enter left child of %d press 1\n",temp->data);
    scanf("%d",&y);
    if (y==1)
    temp->lchild=create();
    printf ("To enter right child of %d press 1\n",temp->data);
    scanf("%d",&y);
    if (y==1)
    temp->rchild=create();
    return temp;
}
int lnodes(node* root)
{
    if (!root)
    return 0;
    if (!root->rchild && !root->lchild)
    return 1;
    return lnodes(root->lchild)+lnodes(root->rchild);
}
int nlnodes(node* root)
{
    if (!root)
    return 0;
    if (!root->rchild && !root->lchild)
    return 0;
    return 1+nlnodes(root->lchild)+nlnodes(root->rchild);
}
int main()
{
    node* root=create();//creation of binary tree..........(a)
    printf ("No. of leaf nodes: %d\n",lnodes(root));
    printf ("No. of non leaf nodes: %d\n",nlnodes(root));
} 