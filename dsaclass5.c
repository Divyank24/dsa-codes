//SINGLY LINKED LIST SORT

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *bottom;
};
struct node *head=NULL;
//Creation of a node
void create()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newn->data);
    newn->next=NULL;
    if(head==NULL)
    {
        head=temp=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    }
 }
 void sort ()
 {
     struct node *cur,*index;
     int temp;
     cur=head;
     if(head==0)
        printf("\nNo nodes to sort");
     else
     {
         while(cur!=0)
         {
             index=cur->next;
             while(index!=0)
             {
                 if(cur->data>index->data)
                 {
                     temp=cur->data;
                     cur->data=index->data;
                     index->data=temp;
                 }
                 index=index->next;
             }
             cur=cur->next;
         }
     }
 }

void main()
{
    int ch;
    printf("\nThe Single Linked List\n");
    while(1)
    {
    printf("\nMENU\n 1.Create node 2.Display 3.Sort 4.Exit");
    printf("\nEnter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:create();
               break;
        case 2:display();
               break;
        case 3:sort();
               break;
        case 4:exit(0);
               break;
        default:
             printf("\nInvalid input choice");
               break;
    }
    }
}
