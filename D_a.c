#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size],rear=-1,front=-1;
void enqueue(int x){
    if(rear==(size-1))
    {
        printf("queue is full.\n");
    }
    else{
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=x;
    }
}
void dequeue_front(){
    if(front==-1){
        printf("queue is empty!\n");
    }
    else{
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }
}
void dequeue_rear(){
    if(front==-1){
        printf("queue is empty!\n");
    }
    else{
        rear--;
    }
}
void display()
{
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
    }
}
int main()
{
    printf("Enter the data to the queue:\n");
    for(int i=0;i<size;i++){
        int element;
        scanf("%d",&element);
        enqueue(element);
    }
    display();
    dequeue_front();
    printf("\n");
    printf("element deleted from front of the queue.\n");
    display();
    dequeue_rear();
    printf("\n");
    display();
}