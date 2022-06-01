#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct telepay
{
    float amt;
    int tid;
    char type[20];
    struct telepay *next;
};
typedef struct telepay *NODE;

NODE getnewnnode();
NODE insert(NODE head);
void display(NODE head);
void search(NODE head);

int main()
{
    NODE head=0;
    int i,n;
    printf("\nEnter the number of transaction");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insert(head);
    }
    display(head);
    search(head);
    return 0;

}
NODE getnewnnode()
{
    NODE newn=(NODE)malloc(sizeof(struct telepay));
    if(newn==0)
    {
        printf("\nMemory not allocated");
        exit(0);
    }
        printf("\nEnter the transaction type amt transaction id");
        scanf("%s %d %f",newn->type,&newn->amt,&newn->tid);
        newn->next=NULL;
    return newn;
}
NODE insert(NODE head)
{
    NODE cur=head;
    NODE newn=getnewnode();
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(cur->next!=0)
            cur=cur->next;

        cur->next=newn;
    }
    return head;
}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%s %f %d",cur->type,cur->amt,cur->tid);
            cur=cur->next;
        }
    }
}
void search(NODE head)
{
    char stype[20];
    int flag=0;
    printf("\nEnter the transaction type");
    scanf("%s",stype);
    NODE cur=head;
    if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        while(cur!=NULL)
        {
            if(strcmp(cur->type,stype)==0)
            {
                flag=1;
                printf("%s %f %d",cur->type,cur->amt,cur->tid);
            }
            cur=cur->next;
        }
        if(flag==0)
        {
            printf("\nTransaction not found");
        }
    }

}
