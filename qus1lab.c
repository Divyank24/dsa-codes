#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct music
{
    char name[20],singer[20];
    float dur;
    int year;
    struct music *next;
};

typedef struct music *NODE;

NODE getnewnode();
NODE insertfront(NODE head);
void displaycll(NODE head);
void displaysinger(NODE head);
void findsong(NODE head);
void sameyear(NODE head);
NODE deletesong(NODE head);

int main()
{
    NODE head=NULL;
    int i,n;
    printf("Enter the number of songs\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insertfront(head);
    }
    displaycll(head);
    displaysinger(head);
    findsong(head);
    sameyear(head);
    head=deletesong(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct music));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
    }
    printf("Enter the song details: Name Singer Duration Year\n");
    scanf("%s%s%f%d",newn->name,newn->singer,&newn->dur,&newn->year);
    newn->next=newn;
    return newn;
}

NODE insertfront(NODE head)
{
    NODE newn=getnewnode();
    NODE cur=head;
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        cur->next=newn;
        newn->next=head;
        head=newn;
    }
    return head;
}

void displaycll(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Songs list id empty\n");
    }
    else
    {
        printf("Songs are\n");
        while(cur->next!=head)
        {
            printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
            cur=cur->next;
        }
        printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
    }
}

void displaysinger(NODE head)
{
    NODE cur=head;
    char ssinger[20];
    int flag=0;
    printf("Enter the singer name\n");
    scanf("%s",ssinger);
    if(head==NULL)
    {
        printf("Songs list is empty\n");
    }
    else
    {
        while(cur->next!=head)
        {
            if(strcmp(cur->singer,ssinger)==0)
            {
                printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
                flag=1;
            }
            cur=cur->next;
        }
        if(strcmp(cur->singer,ssinger)==0)
        {
            printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
            flag=1;
        }
    }
    if(flag==0)
        printf("Singer not found\n");
}

NODE deletesong(NODE head)
{
    NODE prev=NULL,cur=head;
    char sname[20];
    printf("Enter song name to delete\n");
    scanf("%s",sname);
    if(head==NULL)
    {
        printf("Songs list is empty\n");
    }
    else if(head->next==head)
    {
        if(strcmp(head->name,sname)==0)
        {
            printf("Deleted song %s\n",sname);
            free(head);
            head=NULL;
        }
    }
    else if(strcmp(head->name,sname)==0)
    {
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        prev=head;
        cur->next=head->next;
        head=head->next;
        printf("Deleted song is %s",sname);
        free(prev);
    }
    else
    {
        while(cur->next!=head)
        {
            if(strcmp(cur->name,sname)==0)
            {
                prev->next=cur->next;
                printf("Deleted song %s\n",cur->name);
                free(cur);
            }
            prev=cur;
            cur=cur->next;
        }
        if(strcmp(cur->name,sname)==0)
        {
            prev->next=cur->next;//cur->next has address of head node
            printf("Deleted song %s\n",cur->name);
        }
    }
    printf("\n");
    displaycll(head);
    return head;
}

void findsong(NODE head)
{
    NODE cur=head;
    float dnum=0;
    printf("\n");
    printf("The song with highest duration is:\n");
    if(head==NULL)
    {
        printf("Song list is empty\n");
    }
    else
    {
        while(cur->next!=head)
        {
            if(cur->dur>dnum)
            {
                dnum=cur->dur;
            }
            cur=cur->next;
        }
        if(cur->dur>dnum)
        {
            dnum=cur->dur;
        }
        cur=head;
        while(cur->next!=head)
        {
            if(cur->dur==dnum)
            {
                printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
            }
            cur=cur->next;
        }
        if(cur->dur==dnum)
        {
            printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
        }
    }
    printf("\n");
}

void sameyear(NODE head)
{
    NODE cur=head;
    int y,flag=0;
    printf("\n");
    printf("Enter the year to display the songs of that year\n");
    scanf("%d",&y);
    if(head==NULL)
    {
        printf("Song list is empty\n");
    }
    else
    {
        while(cur->next!=head)
        {
            if(cur->year==y)
            {
                printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
                flag=1;
            }
            cur=cur->next;
        }
        if(cur->year==y)
        {
            printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->dur,cur->year);
            flag=1;
        }
        if(flag==0)
        {
            printf("Songs of %d does not exist\n",y);
        }
    }
    printf("\n");
}
