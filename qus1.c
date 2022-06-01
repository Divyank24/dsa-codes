
#include<stdio.>
#include<stdlib.h>
#include<string.h>

struct music
{
    char name[20];
    char song_name[20];
    int duration,year;
    struct music *next;
};
void insert_end()
{
    struct music *temp,*newn;
    newn=(struct music*)malloc(sizeof(struct music));
    printf("\nSINGER NAME SONG NAME DURATION YEAR");
    scanf("%s %s %d %d",newn->name,newn->son_name,&newn->duration,&newn->year);
    if(head==NULL)
    {
        head=newn;
        newn->next=head;
    }
    else
    {
        temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->next=head;
    }

}
void display()
{
    struct music *temp;
    if(head==0)
    {
        printf("\nTHE list is empty");
    }
    else
    {
        temp=head;
        while(temp!=head)
        {
            printf("%s %s %d %d",newn->name,newn->son_name,newn->duration,newn->year);
            temp=temp->next;
        }

    }
}

void del_speci()
{
    struct music *temp,*prev;
    temp=head;
    char sing_name[20];
    printf("\nEnter the singer name to be deleted");
    scanf("%s",sing_name);

    if(head==NULL)
        printf("\n NO NODES TO DELETE");
    else
    {
        while(strcmp(temp->name,sing_name)!=0)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp_next;
    }
}

void del_end()
{
    struct music *temp;

}
