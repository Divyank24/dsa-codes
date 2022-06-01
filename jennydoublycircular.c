/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char grade[2];
    char name[10];
    struct node *next;
    struct node *prev;
};

struct node *head;

void create()
{
    struct node *temp,*newn;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("\nNAME GRADE\n");
    scanf("%s %s",newn->name,newn->grade);
    if(head==0)
    {
        head=temp=newn;
        head->prev=head;
        head->next=head;
    }
    else
    {
        newn->next=head;
        newn->prev=temp;
        temp->next=newn;
        head->prev=newn;
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
        printf("\nThe LIST");
        do
        {
            printf("\n%s %s",temp->name,temp->grade);
            temp=temp->next;
        }
        while(temp!=head);
    }
}
void displaylast_first()
{
    struct node *temp;
    if(head==0)
        printf("\nThe list is empty");
    else
    {
        temp=head->prev;
        printf("\nThe list in reverse order");
        do
        {
            printf("\n%s %s",temp->name,temp->grade);
            temp=temp->prev;
        }
        while(temp!=head->prev);
    }
}
void insert_begin()
{
   struct node *last,*newn;
   newn=(struct node*)malloc(sizeof(struct node));
   printf("\nNAME GRADE\n");
   scanf("%s %s",newn->name,newn->grade);
   if(head==0)
   {
       head=last=newn;
       head->next=head;
       head->prev=head;
   }
   else
   {
       last=head->prev;
       newn->next=head;
       newn->prev=last;
       head->prev=newn;
       last->next=newn;//imp
       head=newn;
   }
}

void insert_end()
{
    struct node *last,*newn;
   newn=(struct node*)malloc(sizeof(struct node));
   printf("\nNAME GRADE\n");
   scanf("%s %s",newn->name,newn->grade);
   if(head==0)
   {
       head=last=newn;
       head->next=head;
       head->prev=head;
   }
   else
   {
       last=head->prev;
       newn->next=head;
       newn->prev=last;
       last->next=newn;
       head->prev=newn;
   }
}

void del_end()
{
    struct node *temp,*last;
    if(head==0)
        printf("\nEmpty List");
    else if(head->next==head)
      {
          temp=head;
          head=0;
          free(temp);
      }
      else
      {
          last=temp=head->prev;
          last=last->prev;
          last->next=head;
          head->prev=last;
          free(temp);
      }
}

void del_front()
{
    struct node *temp,*last;

    if(head==0)
    {
     printf("\nEmpty List");
    }
    else if(head->next==head)
    {
        temp=head;
        head=0;
        free(temp);
    }
    else
    {
        temp=head;
        last=head->prev;
        head=head->next;
        head->prev=last;//imp
        last->next=head;
        free(temp);

    }
}

int main()
{
    int n,i;
     printf("\nEnter the details\n");
    printf("\nEnter the number of students=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    display();
     printf("\n");
    insert_begin();
     display();
     printf("\n");
    insert_end();
     display();
     printf("\n");
     del_end();
      display();
      printf("\n");
      del_front();
      display();
      displaylast_first();



    return 0;
}
*/

//For single character grade
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char grade;
    char name[10];
    struct node *next;
    struct node *prev;
};

struct node *head;

void create()
{
    struct node *temp,*newn;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("\nNAME GRADE\n");
    scanf("\n%s %c",newn->name,&newn->grade);
    if(head==0)
    {
        head=temp=newn;
        head->prev=head;
        head->next=head;
    }
    else
    {
        newn->next=head;
        newn->prev=temp;
        temp->next=newn;
        head->prev=newn;
        temp=newn;
    }
}
void insert_end()
{
    struct node *last,*newn;
   newn=(struct node*)malloc(sizeof(struct node));
   printf("\nNAME GRADE\n");
   scanf("%s %c",newn->name,&newn->grade);
   if(head==0)
   {
       head=last=newn;
       head->next=head;
       head->prev=head;
   }
   else
   {
       last=head->prev;
       newn->next=head;
       newn->prev=last;
       last->next=newn;
       head->prev=newn;
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
        printf("\nThe LIST");
        do
        {
            printf("\n%s %c",temp->name,temp->grade);
            temp=temp->next;
        }
        while(temp!=head);
    }
}
int length()
{
    struct node *temp;
    int count=0;
    if(head==0)
        return count;
    else
        {
            temp=head;
            do
            {
                count ++;
                temp=temp->next;
            }
            while(temp!=head);
        }
        return count;

}

int main()
{
    int i,n,l;
    printf("\nEnter the number of students=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    display();
    printf("\n");
    insert_end();
    display();
    printf("\n");
    l=length();
    printf("\nThe length of the list is %d",l);
}
