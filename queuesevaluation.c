#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define max 20

typedef struct agri
{
    char name[max];
    char tol[max];
    int amt;
    struct agri *next;
}*node;


node front1=NULL;
node rear1=NULL;
node front2=NULL;
node rear2=NULL;

node getnode()
{
    node newn;
    newn=(node)malloc(sizeof(struct agri));
    if(newn==NULL)
    {
        printf("Memory error\n");
        return NULL;
    }

    scanf("%s%s%d",newn->name,newn->tol,&newn->amt);
    newn->next=NULL;
    return newn;
}

void enq1(node newn)
{
    if(rear1==NULL)
    {
        front1=rear1=newn;
    }

    else
    {
        rear1->next=newn;
        rear1=newn;

    }
}

void enq2(node newn)
{
    if(rear2==NULL)
    {
        front2=rear2=newn;
    }

    else
    {
        rear2->next=newn;
        rear2=newn;

    }
}

void display1()
{
    node temp=front1;
    if(front1==NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%s %s %d",temp->name,temp->tol,temp->amt);
        temp=temp->next;
        printf("\n");
    }

}

void display2()
{
    node temp=front2;
    if(front2==NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%s %s %d",temp->name,temp->tol,temp->amt);
        temp=temp->next;
        printf("\n");
    }

}

int main(){
    node newn;
    int n, shrt=0, lon=0,count=0;
    scanf("%d",&n);
    while(n--){
        newn = getnode();
        if (strcmp(newn->tol,"short")==0 && (newn->amt < 50000))
        {
            shrt = newn->amt + shrt;
            enq1(newn);
            count++;
        }
        else if(strcmp(newn->tol,"long")==0 && (newn->amt < 100000)){
            lon = newn->amt +lon;
            enq2(newn);
            count++;
        }

    }
    printf("Short term Application details\n");
    display1();
    if(shrt!=0){
       printf("%d\n",shrt);
    }
    printf("Long term Application details\n");
    display2();
    if(lon!=0){
       printf("%d\n",lon);
    }
    printf("%d\n",count);

}
