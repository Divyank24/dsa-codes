#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

struct stack
{
    char num[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, char s1)
{
    if(s->top == SIZE-1)
     printf("Stack Overflow\n");

    else
    {
        s->top ++;
        s->num[s->top] = s1;
    }
}

int pop(STACK *s)
{
 char s1;
    if(s->top == -1)
    printf("Stack Underflow\n");

    else
    {
        s1=s->num[s->top];
        s->top--;
        return s1;
    }
}

void reversedstring(STACK *s)
{
    int i,flag=0,count=0;
     char s1[10],s2[10];
     printf("\nEnter the string:");
     scanf("%s",s1);
     printf("\nEntered string is %s",s1);

     int len=strlen(s1);
     strcpy(s2,s1);
     for(i=0;i<len;i++)
     {
         push(s,s1);
     }
     for(i=0;i<len;i++)
     {
         s1[i]=pop(s);
     }
     printf("\nReversed string is %s",s1);

     if(strcmp(s1,s2)==0)
        printf("\nEntered string is palindrome");
     else
        printf("\nNot a palindrome");

}
int main()
{
    char data[SIZE];
    STACK st,*s;
    s=&st;
    s->top =-1;
    reversedstring(s);
    return 0;
}
