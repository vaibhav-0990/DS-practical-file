#include<stdio.h>
#include<string.h>
#define size 20
char stack[20];
int top=-1;
void push(char x)
{
    top++;
    stack[top]=x;
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
}
int main()
{
    char exp[size];
    char *ptr,x;
    printf("enter the expression:");
    gets(exp);
    ptr=exp;
    while(*ptr!='\0')
    {
        if(isalnum(*ptr))
        {
            printf("%c",*ptr);
        }
        else if(*ptr=='(')
        {
            push(*ptr);
        }
        else if(*ptr==')')
        {
            while ((x=pop())!='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while(priority(stack[top])>=priority(*ptr))
            {
                printf("%c",pop());
            }
            push(*ptr);
        }
        ptr++;     
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}