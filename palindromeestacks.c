#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stack
{
    char str[10];
    int top;
};
typedef struct stack STACK;


void push(STACK *s, char str)
{

    //s->top=-1;
    if(s->top==9)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top ++;
        s->str[s->top] = str;
    }
}

char pop(STACK *s)
{
    char data;

    if(s->top==-1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        data=s->str[s->top];
        s->top--;
        return data;
    }
}

void reversestring(STACK *s)
{
    int i;
    char str[10],rev[10];
    printf("\nEnter the string:");
    scanf("%s",str);
    printf("\nThe entered string is %s",str);
    strcpy(rev,str);
    int l=strlen(str);
    printf("\nThe length of the string is %d",l);
    for(i=0;str[i]='\0';i++)
       push(s,str[i]);
    for(i=0;i<l;i++)
    {
       str[i]=pop(s);
    }

    if(strcmp(rev,str)==0)
        printf("\nPalindrome");
    else
        printf("\nNot palindrome");
}
int main()
{
    char data;
    STACK st,*s;
    s=&st;
    s->top =-1;
    reversestring(s);
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25

struct stack
{
    char str[SIZE];
    int top;
};
typedef struct stack STACK;

int pop(STACK *s);
void push(STACK *s, int m);
void reversestring(STACK *s);

int main()
{
    char ch, data;
    STACK st, *s;
    s=&st;
    s->top = -1;
    reversestring(s);
    return 0;
}

void push(STACK *s, int m)
{

    s->top == -1;
    if(s->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top ++;
        s->str[s->top] = m;
    }
}

int pop(STACK *s)
{
    char data;
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        data = s->str[s->top];
        s->top--;
        return data;
    }
}

void reversestring(STACK *s)
{
    char str[50], rev[50];
    int l, i;
    printf("Enter a string : ");
    gets(str);
    strcpy(rev,str);
    l=strlen(str);
    for(i=0;str[i]!='\0';i++)
    {
        push(s,str[i]);
    }
    for(i=0;i<l;i++)
    {
        str[i]=pop(s);
    }
    printf("reversed string = %s \n",str);
    if(strcmp(rev,str)==0)
        printf("%s is palindrome\n", rev);
    else
        printf("%s is not palindrome\n", rev);

}*/
