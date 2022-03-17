#include<stdio.h>

struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
};
typedef struct Node *node;

node getnode();
node insert_rear(head);
void display(head);

int main()
{
   node head=NULL;
   int N;
   printf("Enter size of list:\n");
   scanf("%d",&N);

   for(int i=0;i<N;i++)
   {
       head = insert_rear(head);
   }
   display(head);
   return 0;
}

node getnode()
{
    node t;
    int item;
    t=(node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("not created\n");
        exit(0);
    }

    printf("enter the item to be inserted\n");
    scanf("%d",&item);
    t->data=item;
    t->next=NULL;
    t->prev=NULL;
    return t;
}

node insert_rear(node head)
{
    node newnode;
    newnode = getnode();
    if(head==NULL)
    {
        newnode->next = NULL;
        head = newnode;
        return head;
    }
    node temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev = temp;
    newnode->next=NULL;
    return head;
}

void display(node head)
{
  node n;
  if(head==NULL)
  {
      printf("the list is empty\n");
      return head;
  }
  printf("The elements in the list are\n");
  n=head;
  while(n!=NULL)
  {
      printf("%d\t",n->data);
      n=n->next;
  }
  printf("\n");
}
