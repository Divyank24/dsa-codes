#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *node;
node insert_rear(head,N);
node left_shift(head,N,K);
void display_list(head);

int main()
{
   node head = NULL;
   int N;
   printf("Enter the size of linked list:\n");
   scanf("%d",&N);
   int K;
   printf("Enter the nodes the is to be left shifted k times:\n");
   scanf("%d",&K);

   for(int i=0;i<N;i++)
   {
   head = insert_rear(head,N);
   }
   head = left_shift(head,N,K);
   display_list(head);
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
    return t;
}

node insert_rear(node head,int N)
{
  node t;
  node c;
  t=getnode();
  if(head==NULL)
  {
    return t;
  }
  c=head;
  for(int i=0;i<N;i++)
  while(c->next!=NULL)
  {
      c=c->next;
  }
  c->next=t;
  return  head;
}

void display_list (node head)
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

node left_shift(node head,int N,int K)
{
        node cur = head;
        for(int i = 1; i<K; i++){
            cur = cur->next;
        }
        node tail = cur;
        node new_head = cur->next;

        if(new_head == NULL)
            {
            return head;
        }

        while(cur->next != NULL){
            cur = cur->next;
        }

        cur->next = head;
        tail->next = NULL;

        return new_head;
}
