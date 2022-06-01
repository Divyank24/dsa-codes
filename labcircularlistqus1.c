#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct music
{
char name[20], singer[20];
float duration;
int year;
struct music *next;
};
typedef struct music *NODE;

NODE getnewnode()
{
NODE newn = (NODE)malloc(sizeof(struct music));
if(newn==NULL)
{
 printf("Memory not allocated\n");
 exit(0);
}
 printf("Enter Song details: name, singer name, duration, year\n");
 scanf("%s%s%f%d", newn->name, newn->singer, &newn->duration, &newn->year);
 newn->next = newn;
 return newn;
}

NODE insert_front(NODE head)
{
NODE newn = getnewnode();
NODE cur=head;
if(head==NULL)
{
head=newn;
}
else
{
while(cur -> next != head)
{
cur = cur -> next;
}
cur->next = newn;
newn->next = head;
head=newn;
}
return head;
}

void display_csll(NODE head)
{
NODE cur=head;
if(head==NULL)
{
printf("Songs list is empty\n");
}
else
{
printf("Songs are\n");
while(cur->next != head)
{
printf("%s %s %0.2f %d\n", cur->name, cur->singer, cur->duration, cur->year);
cur = cur->next;
}
printf("%s %s %0.2f %d\n", cur->name, cur->singer, cur->duration, cur->year);
}
}

void display_singer(NODE head)
{
NODE cur=head;
char ssinger[20];
int flag=0;
printf("Enter singer name: ");
scanf("%s",ssinger);
if(head==NULL)
printf("Songs list is empty\n");
else
{
while(cur->next !=head)
{
if(strcmp(cur->singer,ssinger)==0)
{
printf("%s %s %0.2f %d\n", cur->name, cur->singer, cur->duration, cur->year);
flag = 1;
}
cur = cur->next;
}
if(strcmp(cur->singer,ssinger)==0)
{
printf("%s %s %0.2f %d\n", cur->name, cur->singer, cur->duration, cur->year);
flag=1;
}
}
if(flag==0)
{
printf("Singer songs not present\n");
}
}

NODE delete_song(NODE head)
{
NODE prev = NULL, cur=head;
char sname[20];
printf("Enter song name to delete\n");
scanf("%s",sname);
if(head==NULL)
{
printf("Songs list is empty\n");
}
else if(head->next==head)
{
if(strcmp(head->name, sname)==0)
{
printf("Deleted song %s\n",prev->name);
free(head);
head=NULL;
}
}
else if(strcmp(head->name, sname)==0)
{
while(cur -> next !=head)
{
cur = cur->next;
}
prev=head;
cur->next=head->next;
head = head->next;
printf("Deleted song %s\n",prev->name);
free(prev);
}
else
{
while(cur -> next != head)
{
if(strcmp(cur->name, sname)==0)
{
prev->next = cur->next;
printf("Deleted song %s\n",cur->name);
free(cur);
}
prev=cur;
cur = cur->next;
}
if(strcmp(cur->name,sname)==0)
{
prev->next=cur->next; // cur->next has address of head node.
printf("deleted song %s\n",cur->name);
}
}
printf("\n");
display_csll(head);
return head;
}

void highest (NODE head)
{
    float max=0;
    NODE cur,temp;
    cur=head;
    max=cur->duration;
    cur=cur->next;
     do
    {
        if(cur->duration>max)
        {
            max=cur->duration;
        }
    cur=cur->next;
    }while(cur!=head);
    cur=head;
    do
    {
        if(cur->duration==max)
        {
            printf("\nHighest Duration :\n");
            printf("%s %s %0.2f %d\n", cur->name, cur->singer, cur->duration, cur->year);
        }
    cur=cur->next;
    }while(cur!=head);
}

void searchyear(NODE head)
{
NODE cur=head;
int flag=0,s=0;
printf("\nEnter the year: ");
scanf("%d",&s);
if(head==NULL)
{
    printf("Songs list is empty\n");
}
else
{
 do
{
if(cur->year==s)
{
printf("%s %s %0.2f %d\n", cur->name, cur->singer, cur->duration, cur->year);
flag = 1;
}
cur = cur->next;
}while(cur!=head);
}

if(flag==0)
{
printf("Singer songs not present\n");
}
}

int main()
{
NODE head=NULL;
int i,n;
printf("Enter number of songs\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
head=insert_front(head);
}
display_csll(head);
display_singer(head);
highest(head);
searchyear(head);
head=delete_song(head);

return 0;
}
