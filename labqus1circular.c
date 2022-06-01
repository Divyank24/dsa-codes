#include<stdio.h>
struct node
{
    char name[10];
    char gender[10];
    struct node *next;
}*tail;

void create()
{
    struct node *newn,*temp;
    head=0;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the name and gender\n");
    scanf("%s %s",newn->name,newn->gender);
    newn->next=0;
    if(head==0)
    {
        head=temp=newn;
    }
    else
    {
     temp->next=newn;
     temp=newn;
    }
    temp->next=head;
}

 void display()
 {
     struct node *temp;
     if(head==0)
     {
         printf("\nEmpty list");
     }
     else
     {
         temp=head;
         while(temp->next!=head)
         {
             printf("%s %s",temp->name,temp->gender);
             temp=temp->next;
         }
         printf("%s %s",temp->name,temp->gender);
     }
 }
 void atbegin()
 {
     strcut node *newn;
     newn=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the name gender");
     scanf("%s %s",newn->name,newn->gender);
     newn->next=0;
     if(tail==0)
     {
         tail=newn;
         tail->next=newn;
     }
     else
     {
         newn->next=tail->next;
         tail->next=newn;
     }
 }
 void addatend()
 {
     struct node *newn;
     newn=(struct node*)malloc(sizeof(struct node));
     printf("\Enter the name gender");
     scanf("%s %s",newn->name,newn->gender);
     newn->next=0;
     if(tail==0)
     {
         tail=newn;
         tail->next=newn;
     }
     else
     {
         newn->next=tail->next;
         tail->next=newn;
         tail=newn;
     }
 }
 void addspecific()
 {
     struct node *newn,*temp;
     inr pos,i=1;
     printf("\nEnter the position");
     sacnf("%d",&pos);
     l=getlength();
     if(pos<0||pos>l)
     {
         printf("\nInvalid position");
     }
     else if(pos==1)
     {
         atbegin();
     }
     else
     {
         newn=(struct node*)malloc(sizeof(struct node));
         printf("\nEnter the name and gender\n");
         scanf("%s %s",newn->name,newn->gender);
         newn->next=0;
         temp=tail->next;
         while(i<pos-1)
         {
             temp=temp->next;
             i++;
         }
         newn->next=temp->next;
         temp->next=newn;
     }
 }
 void delspeci()
 {
     struct node *current,*nextnode;
     int pos,i=1,l;
     current=tail->next;
     printf("\nEnter the position\n");
     scanf("%d",&pos);
     l=getlength();
     if(pos<1 || pos>l)
     {
         printf("\nThe invalid position");
     }
     else if(pos==1)
     {
         delfrombegin();
     }
     else
     {
         while(i<pos-1)
         {
            current=current->next;
            i++;
         }
         nextnode=current->next;
         current->next=nextnode->next;
         free(nextnode);
     }
 }
 void delbegin()
 {
     strcut node *temp;
     temp=tail->next;
     if(tail==0)
     {
         printf("\nInvalid");
     }
     else if(temp->next==temp)
     {
         tail=0;
         free(temp);
     }
     else
     {
         tail->next=temp->next;
         free(temp);
     }
 }
 void delfromend()
 {
     struct node *current,*previous;
     current=tail->next;
     if(tail==0)
     {
        printf("\nInvalid");
     }
     else if(current->next==current)
     {
         tail=0,free(current);
     }
     else
     {
         while(current->next!=tail->next)
         {
         previous=current;
         current=current->next;
       }
     previous->next=tail->next;
     tail=previous;
     free(current);
     }
 }
 void main()
 {

 }
