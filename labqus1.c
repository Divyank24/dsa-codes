#include<stdio.h>
struct node
{
    char g[20];
    struct node *next;
};
void readinfo(struct node *p)
{
    printf("enter the gender M=male, F=female  O=others\n");
    scanf("%s",p->g);
}
void displayinfo(struct node *p)
{
    printf("%s\n",p->g);
}
struct node *insertfront(struct node *first)
{
    struct node *nw;
    nw=(struct node *)malloc(sizeof(struct node));
    readinfo(nw);
    if(first==NULL)
    {
        first=nw;
    }
    else
    {
        nw->next=first->next;
    }
    first->next=nw;
    return first;
};
void displaylist(struct node *first)
{
    struct node *cur;
    cur=first;
    do
    {
        displayinfo(cur);
        cur=cur->next;
    }while(cur!=first);
}
struct node *insertfemale(struct node *p,struct node *first)
{
    struct node *p1,*cur;
    for(cur=p;cur->g!='F';cur=cur->next);

    p1=p->next;
    if(cur->next==first)
        p1->next=first;
    else
        p1->next=cur->next;
    p->next=cur;
    cur->next=p1;
    return first;
};
struct node *insert(struct node *first)
{
    struct node *p;
    p=first;
    if(strcmp(p->g,p->next->g)==0)
    {
        if(p->g=='M')
            first=insertfemale(p,first);
    }
    printf("\n The updated list is \n");
    displaylist(first);
    return first;
};
struct node *removeO(struct node *first)
{
    struct node *p1,*p2;
    for(p1=first,p2=NULL;p2!=NULL;p2=p1,p1=p1->next)
    {
        if(p1->g=='O')
        {
            p2->next=p1->next;
            free(p1);
        }
    }
    printf("\n The updated list is \n");
    displaylist(first);
    free(p1);

    return first;
};
int main()
{
    struct node *first=NULL;
    int N,i;
    printf("Enter the number\n");
    scanf("%d",&N);
    for(i=0;i<N;i++)
        first=insertfront(first);
    printf("the list is: \n");
    displaylist(first);
    first=insert(first);
    first=removeO(first);
    printf("\n The updated list is \n");
    displaylist(first);

}
