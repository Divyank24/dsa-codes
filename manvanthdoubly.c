#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct music
{
    char name[20],singer[20],movie[20];
    float size;
    struct music* next;
    struct music* prev;
};
typedef struct music* NODE;
NODE read()
{
    NODE newn=malloc(sizeof(struct music));
    if(newn==NULL)
    {
        printf("no node created");
        exit(1);
    }
    printf("enter the name singer movie and size of song in mb\n");
    scanf("%s%s%s%f",newn->name,newn->singer,newn->movie,&newn->size);
    newn->prev=NULL;
    newn->next=NULL;
    return newn;
}
NODE insert_end(NODE head)
{
    NODE newn=read(),cur=head;
    if(head==NULL)
        return newn;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=newn;
    newn->prev=cur;
    return head;
}
void disp(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        printf("song singer movie size of song in mb\n");
        while(cur!=NULL)
        {
            printf("%s %s %s %f\n",cur->name,cur->singer,cur->movie,cur->size);
            cur=cur->next;
        }
    }
}
NODE insert_spec(NODE head)
{
    NODE cur=head,temp=read(),back=NULL;
    char s[20];
    printf("enter the song name after which to be added\n");
    scanf("%s",s);
    while(cur!=NULL)
    {
        if(strcmp(s,cur->name)==0)
        {
            if(cur->next==NULL)
            {
                cur->next=temp;
                temp->prev=cur;
                return head;
            }
            back=cur;
            cur=cur->next;
            back->next=temp;
            temp->prev=back;
            temp->next=cur;
            cur->prev=temp;
            return head;

        }
        cur=cur->next;
    }
    printf("no songs found to insert\n");
    return head;
}
NODE del(NODE head)
{
    NODE cur=head,back=NULL,temp=NULL;
    char s[20];
    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    printf("enter the song name to be deleted\n");
    scanf("%s",s);
    while(cur!=NULL)
    {
        if(strcmp(s,cur->name)==0)
        {
            if(cur==head&&cur->next==NULL)
            {
                printf("deleted song is %s\n",cur->name);
                head=NULL;
                free(cur);
                return NULL;
            }
            else if(cur==head)
            {
                  printf("deleted song is %s\n",cur->name);
                back=cur->next;
                back->prev=NULL;
            free(cur);
            return back;
            }
            else if(cur->next==NULL)
            {
                  printf("deleted song is %s\n",cur->name);
                back=cur->prev;
                back->next=NULL;
                free(cur);
                return head;
            }
              printf("deleted song is %s\n",cur->name);
            back=cur->prev;
            temp=cur->next;
            back->next=temp;
            temp->prev=back;
            free(cur);
            return head;
      }
      cur=cur->next;
    }
    printf("no such song found to delete\n");
    return head;
}

int main()
{
  int ch;
NODE head=NULL;
while(1)
{
printf("\nDLL menu\n1.Insert End\n2.Display\n3.Insert After\n4.Delete Specific\n5.Exit\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: head=insert_end(head);
break;
case 2:  disp(head);
break;
case 3: head=insert_spec(head);
break;
case 4:  head=del(head);
break;
case 5:exit(0);
break;
default: printf("Invalid Choice\n");


}
}
return 0;
}
