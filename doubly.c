#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;
int l;
int length()
{
    struct node *temp;
    int count=0;
    if(head==0)
        printf("\nEmpty list");
    else
    {
        temp=head;
        while(temp!=0)
        {
            temp=temp->next;
            count ++;
        }
    }
    return count;
}
void create()
{

    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nData:");
    scanf("%d",&newn->data);
    newn->prev=0;
    newn->next=0;

    if(head==0)
    {
        head=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
        temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void display()
{
    struct node *temp;
    if(head==0)
        printf("\nThe list is empty");
    else
    {
        temp=head;
        printf("NULL");
        while(temp!=NULL)
        {
            printf("<-[%d]->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}
void insert_end()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nData:\n");
    scanf("%d",&newn->data);
    newn->next=0;
    newn->prev=0;

    if(head==0)
    {
        head=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void insert_begin()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nData:\n");
    scanf("%d",&newn->data);
    newn->next=0;
    newn->prev=0;

    if(head==NULL)
    {
        head=newn;
    }

    else
    {
        temp=head;
        head->prev=newn;
        newn->next=head;
        head=newn;
    }

}
void insert_at_loc()
{
    struct node *newn,*temp,*front;
    int i=1,loc;

    if(head==0)
        printf("\nNo nodes are present");

    else
    {
        printf("\nEnter the location at which the node is to be inserted=");
        scanf("%d",&loc);

        if(loc==1)
        {
            insert_begin();
        }
        else if(loc<1||loc>length())
        {
            printf("\nInvalid input location");
        }
        else
        {
            temp=head;
            newn=(struct node*)malloc(sizeof(struct node));
            printf("Enter the details");
            printf("\nData:\n");
            scanf("%d",&newn->data);
            newn->next=0;
            newn->prev=0;
            while(i<loc)
            {
                temp=temp->next;
                i++;
            }
            front=temp->next;


            newn->next=temp->next;
            newn->prev=temp;
            temp->next=newn;
            front->prev=newn;

        }

    }
}

void main()
{
    int ch;
    while(1)
    {
    printf("\nMENU\n1.Create 2.Display 3.Insert end 4.Insert begin 5.Length 6.Insert specific 7.Exit");
    printf("\nEnter the choice=");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:create();
               break;
        case 2:display();
               break;
        case 3:insert_end();
               break;
        case 4:insert_begin();
               break;
        case 5:l=length();
        printf("\nThe length of the list is %d",l);
               break;
        case 6:insert_at_loc();
               break;
        case 7:exit(0);
               break;
        default:
            printf("\nInvalid choice");

    }
    }

    }
