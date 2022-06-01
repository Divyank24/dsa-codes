#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[25];
    int id,amt;
    char gender[25];
    struct node *next;
};
struct node *head=NULL;
int len;
//Creation of a node
void create()
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data");
    printf("\nName Transaction Id Gender Amount\n");
    scanf("%s %d %s %d",newnode->name,&newnode->id,newnode->gender,&newnode->amt);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
         temp=temp->next;
        }
        temp->next=newnode;
     }-
    }

void insert_begin()
{
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nName Transaction Id Gender Amount\n");
    scanf("%s %d %s %d",newnode->name,&newnode->id,newnode->gender,&newnode->amt);
    newnode->next=head;
    head=newnode;
    }

void insert_specific()
    {
        struct node*temp,*newnode;
        int i=1,loc;
        printf("\nEnter the location after which the node has to be inserted= ");
        scanf("%d",&loc);
        if(loc>len)
        {
            printf("\nInvalid input location");
        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            temp=head;
            while(i<loc)
            {
                temp=temp->next;
                i++;
            }
            printf("\nName Transaction Id Gender Amount\n");
            scanf("%s %d %s %d",newnode->name,&newnode->id,newnode->gender,&newnode->amt);
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

void insert_end()
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=head;
    printf("\nName Transaction Id Gender Amount\n");
    scanf("%s %d %s %d",newnode->name,&newnode->id,newnode->gender,&newnode->amt);
    newnode->next=0;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
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
        printf("%s %d %s %d\n",temp->name,temp->id,temp->gender,temp->amt);
        temp=temp->next;
    }
    }
 }

 int length()
 {
     struct node *temp;
     len=0;
     if(head==NULL)
     {
         printf("\nThe length of the list is %d",len);
     }
     else
     {
         temp=head;
         while(temp!=0)
         {
             temp=temp->next;
             len++;
         }
     }
     return len;

 }
 void del_begin()
 {
     struct node *temp;
     if(head==NULL)
        printf("\nThe list is empty");
     else
     {
         temp=head;
         head=head->next;
         free(temp);
     }
 }

 void del_end()
 {
     struct node *temp,*prev;
     temp=head;
     while(temp->next!=0)
     {
         prev=temp;
         temp=temp->next;
     }
     if(temp==head)
     {
         head=0;
     }
     else
     {
         prev->next=0;
     }
     free(temp);
 }

 void del_specific()
 {
     struct node *temp,*nextnode;
     int loc,i=1;
     printf("\nEnter the location to be deleted= ");
     scanf("%d",&loc);
     if(loc>length())
     {
        printf("\nInvalid input location");
     }
     else
     {
         temp=head;
         while(i<loc-1)
         {
             temp=temp->next;
             i++;
         }
         nextnode=temp->next;
         temp->next=nextnode->next;
         free(nextnode);
     }
 }
void main()
{
    int ch;
    printf("\nThe Single Linked List\n");
    while(1)
    {
    printf("\nMENU\n 1.Create node 2.Display 3.Insert end 4.Insert begin 5.Insert specific 6.Length of node 7.Delete begin 8.Delete end 9.Delete specific 10.Exit");
    printf("\nEnter the choice\n");
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
        case 5:insert_specific();
               break;
        case 6:len=length();
               printf("\nThe length of the list is %d",len);
               break;
        case 7:del_begin();
               break;
        case 8:del_end();
               break;
        case 9:del_specific();
               break;
        case 10:exit(0);
               break;
        default:
             printf("\nInvalid input choice");
               break;
    }
  }
}
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[25];
    int id,amt;
    char gender[25];
    struct node *next;
};
struct node *head=NULL;
//Creation of a node
void create()
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data");
    printf("\nName Transaction Id Gender Amount\n");
    scanf("%s %d %s %d",newnode->name,&newnode->id,newnode->gender,&newnode->amt);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        //idu kodlillagidde ninu ....temp=head;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
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
        printf("%s %d %s %d",temp->name,temp->id,temp->gender,temp->amt);
        temp=temp->next;
    }
    }
 }

void main()
{
    int ch;
    printf("\nThe Single Linked List\n");
    while(1)
    {
    printf("\nMENU\n 1.Create node 2.Display 3.Exit");
    printf("\nEnter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:create();
               break;
        case 2:display();
               break;
        case 3:exit(0);
               break;
        default:
             printf("\nInvalid input choice");
               break;
    }
    }
}*/
