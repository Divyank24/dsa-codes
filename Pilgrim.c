#include <stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}*List;

int count=0;

List create()
{
    List newn;
    newn=malloc(sizeof(struct node));
    count++;
    newn->next=NULL;
    return newn;
}

List insertrear(List head,int age)
{
    List temp,p=head;
    temp=create();
    temp->data=age;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    }
    return head;
}

void display(List head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
    }
}

List insertatpos(List head,int age,int m)
{

    List temp,prev,cur;
    int c=0;
    temp=create( );
    temp->data=age;
    cur=head;
    prev=NULL;
    if(m==0)
    {
        head->next=temp;
        //return first;
    }
    else
        {
    while(cur->next!=NULL && c!=m)
    {
        c++;
        prev=cur;
        cur=cur->next;
    }
    prev->next=temp;
    temp->next=cur;
    }
    return head;
}

int main()
{
    List head=NULL;
    int age,n,m,i;
        printf("Enter number of pilgrims\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                    printf("enter age of pilgrim\n");
                    scanf("%d",&age);
                    if(count==0)
                        head=insertrear(head,age);
                    else
                    {
                        if(head->data<age)
                        {
                          m=count/2;
                          head=insertatpos(head,age,m);
                        }
                        else
                            head=insertrear(head,age);
                    }
        }
    display(head);
    return 0;
}

