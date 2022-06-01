#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int n;
    struct node *next;
    struct node *prev;
}  *node;



node getnode ()
 {
     node newn;
     newn=(node) malloc(sizeof (struct node));
     newn->next=NULL;
     newn->prev=NULL;
     printf("\nEnter the height");
     scanf("%d",&new1->n);
     return new1n;
 }
  node insert(node head)
 {
     node cur=head;
     node newn=getnode();
     if(head==NULL)
     return newn;
     while(cur->next!=NULL)
     {
         cur=cur->next;
     }
     cur->next=newn;
     newn->prev=cur;
     newn->next=NULL;
     return head;
 }

 void compare(node head)
{
    node cur=head;
    int count=0;
    if(cur->n>150&&cur->n<cur->next->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    cur=cur->next;
    while(cur->next!=NULL)
    {
          if(cur->n>150&&cur->n<cur->next->n&&cur->n>cur->prev->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    cur=cur->next;
    }
     if(cur->n>150&&cur->n>cur->prev->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    printf("\n%d",count);

    }
int main()
{
    node head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head=insert(head);
    }

    compare(head);

    return 0;
}


void compare_dis()
{
    struct node* cur=head;
    int count=0;
    if(cur->data>150&&cur->data<cur->next->data)
    {
        count++;
        printf("\n%d  ",cur->data);
    }
    cur=cur->next;
    while(cur->next!=NULL)
    {
          if(cur->data>150&&cur->data<cur->next->data&&cur->data>cur->prev->data)
    {
        count++;
        printf("\n%d  ",cur->data);
    }
    cur=cur->next;
    }
     if(cur->data>150&&cur->data>cur->prev->data)
    {
        count++;
        printf("%d  ",cur->data);
    }
    printf("\n%d",count);

    }
