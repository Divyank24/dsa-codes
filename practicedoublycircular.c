#include<stdlib.h>
#include<stdio.h>

struct mangoes
{
    int ripe;
    struct mangoes *prev;
    struct mangoes *next;
};
typedef struct mangoes *NODE;

NODE getnewnode()
{
   NODE newn;
   newn = (NODE)malloc(sizeof(struct mangoes));
   if(newn==NULL)
   {
    printf("Not Created\n");
    exit(0);
   }
 printf("Enter Ripe Level:\n");
 scanf("%d",&newn->ripe);
 newn->next= newn;
 newn->prev= newn;
return newn;
}

NODE insert_front (NODE head)
{
    NODE temp,cur;
    temp=getnewnode();
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
      cur=head->prev;
      //Newnode to head
      temp->next=head;
      head->prev=temp;
      //Connect newnode to last node
      temp->prev=cur;
      cur->next=temp;
      head=temp;
    }
    return head;
}


NODE insert_end(NODE head)
{
    NODE cur,temp;
    temp=getnewnode();
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
        //Mark the last node
        cur=head->prev;

        //Connect newnode to last node
        temp->prev=cur;
        cur->next=temp;

        //Connect newnode to first/head node
        temp->next=head;
        head->prev=temp;
    }
    return head;
}


void display_list(NODE head)
{
    NODE cur=NULL;
     if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        cur=head;
        printf("\nRipe level:\n");
            do
            {
            printf(" %d",cur->ripe);
            cur=cur->next;
            }while(cur!=head);
    }
}

NODE delete_front(NODE head)
{
    NODE del=NULL,cur=NULL;
    if(head==NULL)
        printf("List is Empty\n");
    else if(head->next==head) // Check for one node
    {
        printf("\nMango Falls with ripe level = %d",head->ripe);
        free(head);
        head=NULL;
    }
    else
      {
          cur=head->prev;   //Mark last Node
          del=head;         //Mark First Node
          head=head->next;   //Shift head to next node

         //Connect head to last node
          cur->next=head;
          head->prev=cur;
          printf("\nMango falls with ripe level = %d",del->ripe);
          free(del);
      }
      return head;
}

void falling_mangoes(NODE head)
{
    NODE tail=NULL;
    int count =0,s=0;
    if(head==NULL)
        printf("List is Empty\n");
    else
    {
        tail=head->prev;
        while(head!=tail)
        {
            if((head->ripe)>(head->next->ripe))
            {
                head=delete_front(head);
                count++;
            }
            else
            {
                head=head->next;
                s++;
            }
        }
        if((head->ripe)>(head->next->ripe))
            {
                head=delete_front(head);
                count++;
            }
            else
            {
                head=head->next;
                s++;
            }
    }
    printf("\nList after mangoes falling\n");
    display_list(head);
    printf("\nFallen mangoes= %d\n",count);
    printf("Not fallen manges= %d\n",s);
}

int main()
{
    int i,n;
    NODE head=NULL;
    printf("Enter the number of mangoes :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    display_list(head);
    falling_mangoes(head);
    return 0;
}
