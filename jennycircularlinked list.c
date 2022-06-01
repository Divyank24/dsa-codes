
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[10];
    float dur;
    int year;
    struct node *next;
};

struct node *head;
int l;

void create()
{
    struct node *temp,*newn;
    newn=(struct node*)malloc(sizeof(struct node));
    newn->next=0;

    printf("\nEnter the details\n");
    printf("MOVIENAME DURATION(HRS) YEAR\n");
    scanf("%s %f %d",newn->name,&newn->dur,&newn->year);

    if(head==0)
    {
        head=temp=newn;
        newn->next=head;
    }
    else
    {
        temp=head;
        {
        do
        {
            temp=temp->next;
        }
        while(temp!=head);
        }
        temp->next=newn;
        newn->next=head;
    }
}

void insert_end()
{
    struct node *temp,*newn;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("MOVIENAME DURATION(HRS) YEAR\n");
    scanf("%s %f %d",newn->name,&newn->dur,&newn->year);
    newn->next=0;

    if(head==0)
    {
        head=newn;
        newn->next=head;
    }

    else
    {
        temp=head;
        {
        do
        {
            temp=temp->next;
        }
        while(temp!=head);
        }
        newn->next=temp->next;
        temp->next=newn;
        temp=newn;
    }

}

void insert_begin()
{
    struct node *temp,*newn;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("MOVIENAME DURATION(HRS) YEAR\n");
    scanf("%s %f %d",newn->name,&newn->dur,&newn->year);
    newn->next=0;

    if(head==0)
    {
        head=temp=newn;
        newn->next=head;
    }
    else
    {
        temp=head;
        newn->next=head;
        head=newn;
    }

}

int length()
{
    int count=0;
    struct node *temp;
    if(head==0)
        printf("\n The length of the node is %d",count);
    else
    {
        temp=head;
        do
        {
            temp=temp->next;
            count++;
        }
        while(temp!=head);
    }
    return count;

}

void insert_specific()
{
    struct node *newn,*temp;
    int loc,i=1,l;
    printf("\nEnter the location");
    scanf("%d",&loc);

    if(head==0)
    {
        head=temp=newn;
        newn->next=head;
    }
    else if(loc<0 || loc>l)
        printf("\nInvalid input location");
    else if(loc==1)
    {
        insert_begin();
    }
    else if(loc==l)
    {
        insert_end();
    }
    else
    {
        temp=head;
        {
            do
            {
                temp=temp->next;
                i++;
            }
            while(i<loc-1);
        }
        newn->next=temp->next;
        temp->next=newn;
        temp=newn;
    }
}

void display()
{
    struct node *temp;
    if(head==0)
    {
        printf("\nThe list is empty");
    }
    else
    {
        temp=head;
        do
        {

            printf("%s %f %d",temp->name,temp->dur,temp->year);
            temp=temp->next;
        }
        while(temp!=head);
    }
}

void del_front()
{
    struct node *temp;
    if(head==0)
        printf("\n No nodes to delete");
        else if(head->next==head)
        {
            printf("\nSingle node in the list");
            head=0;
            free(head);
        }
    else
    {
        temp=head;
        head=head->next;
        temp->next=0;
        free(temp);
    }
}

void del_end()
{
    struct node *temp,*prev;
    if(head==0)
    {
        printf("\nNo nodes to delete");

    }
    else if(head->next==head)
    {
        printf("\nSIngle node in the list");
        head=0;
        free(head);
    }
    else
    {
        temp=head;
        prev=0;
        {
            do
            {
                prev=temp;
                temp=temp->next;
            }
            while(temp!=head);
        }
        prev->next=temp->next;
        temp->next=0;
        free(temp);
    }
}

void del_speci()
{
    struct node *temp,*prev;
    int loc,i=1;
    printf("\nEnter the location");
    scanf("%d",&loc);

    if(loc<0 || loc>l)
        printf("\nInvalid input location");
    else if(loc==1)
        del_front();
    else if(loc=l)
    {
        del_end();
    }
    else
    {
        temp=head;

            {

            do
            {
                prev=head;
                temp=temp->next;
                i++;
            }
            while(i<=loc-1);
          }
          prev->next=temp->next;
          temp->next=0;
          free(temp);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\nMENU");
        printf("\n 1.Creation 2.Display 3.Length 4.Insert end 5.Insert begin 6.Insert Specific 7.Delete end 8.Delete Front 9.Delete specific 10.Exit");
        printf("\nEnter the choice=");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create();
                   break;
            case 2:display();
                   break;
            case 3:l=length();
               printf("\nThe length of the function is %d",l);
                   break;
            case 4:insert_end();
                   break;
            case 5:insert_begin();
                   break;
            case 6:insert_specific();
                   break;
            case 7:del_end();
                   break;
            case 8:del_front();
                   break;
            case 9:del_speci();
                   break;
            case 10:exit(0);
                   break;
        }
    }
}
