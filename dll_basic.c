#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
    struct NODE *prev;
    };
typedef struct NODE *node;
node getnode();
node insert_front(head);
void display_list_forward(head);
void display_list_backward(head);
node insert_rare(head);

main()
{
  node head = NULL;
  int choice;
  while(1)
  {
     printf("1-Insert front\n2-Insert rare\n3-Display forward\n4-Display backward\n5-Exit\n");
     scanf("%d",&choice);
      switch(choice)
      {
          case 1 : head = insert_front (head);
                      break;
          case 2 : head = insert_rare (head);
                      break;
          case 3 : printf("Display list inserted in forward\n");
                   display_list_forward(head);
                      break;
          case 4 : printf("Display list Inserted in backward\n");
                   display_list_backward(head);
                      break;
          case 5 : exit(0);
         }
    }
}

node getnode()
{
    node new;
    int element;
    new = malloc (sizeof(struct NODE));
    if(new==NULL)
    {
       printf("Memory not allocated\n");
       exit(0);
       }
    printf("Enter the number:\n");
    scanf("%d",&element);
    new->data = element;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

node insert_front(node head)
{
   node newnode;
   newnode = getnode();
   if(head==NULL)
   {
       head = newnode;
       return head;
       }
    else
    {
       newnode->next=head;
       head->prev=newnode;
       head = newnode;
       return head;
       }
}

node insert_rare(node head)
{
   node newnode;
   newnode = getnode();
   if(head==NULL)
   {
       head = newnode;
       return head;
       }
   else
   {
       node cur=head;
       while(cur->next!=NULL)
       {
          cur=cur->next;
          }
        cur->next = newnode;
        newnode->prev = cur;
        return head;
        }
}

void display_list_forward(node head)
{
    node t;
    if(head == NULL)
    {
        printf("Empty list\n");
        return;
        }
    else
    {
        printf("Elements are:\n");
        t=head;
        while(t->next!=NULL)
        {
           printf("%d\t",t->data);
           t=t->next;
           }
        printf("%d\t", t->data);
        return;
         }
}

void display_list_backward(node head)
{
    node t,p;
    if(head == NULL)
    {
       printf("Empty list\n");
       return;
       }
    printf("Elements are:\n");
    t = head;

    while(t->next!=NULL)
     {
        t = t->next;
        }
        p = t;
    while(p->prev != NULL)
     {
        printf("%d\t",p->data);
        p = p->prev;
        return;
         }
     printf("%d\t",p->data);
     return;
}
