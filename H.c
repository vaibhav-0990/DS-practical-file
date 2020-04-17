#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
}node;
node* root=NULL;
node*stack[10000];
int top=-1;
node* insert(node* root,int key)
{
    if (root==NULL)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->lchild=temp->rchild=NULL;
        temp->data=key;
        return temp;
    }
    if (root->data>key)
    root->lchild=insert(root->lchild,key);
    if (root->data<key)
    root->rchild=insert(root->rchild,key);
    return root;
}
node* create()
{
    int key,y;
    printf ("To insert a node press 1\n");
    scanf("%d",&y);
    if (y==1)
    {
        printf ("Enter data to be inserted\n");
        scanf("%d",&key);
        root=insert(root,key);
    }
    else return root;
    return create ();  
}
void push(node* t)
{
    if (top==9999)
    {
        printf ("Stack is full");
        exit(0);
    }
    top++;
    stack[top]=t;
}
void pop()
{
    if (top==-1)
    {
       printf ("Underflow");
        exit(0); 
    }
    printf ("%d ",stack[top]->data);
    top--;
}
void traverse(node* t)
{
    while(1)
    {
        while(t)// yaha se ye confirm ho gaya t ke left me kuch nahi bachega
        {
            push(t);
            t=t->lchild;
        }
        if (top==-1)
        break;
        t=stack[top];
        pop();
        t=t->rchild;// ab uske right me check kar lete hai
    }
    printf("\n");
}
int height (node* root)
{
   if (root==NULL)return 0;
   if (root->rchild==NULL && root->lchild==NULL)return 0;
    return (1+height(root->lchild)+height(root->rchild));
}
int main(void)
{
    root=create();
    traverse(root);
    printf ("%d",height(root));
}