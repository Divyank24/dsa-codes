#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[20];
    int transaction_id,amt;
    struct node* link;
};
struct node* root=NULL;
int len;

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be stored\n");
    printf("\nName Transaction ID Amount\n");
    scanf("%s %d %d",temp->name,&temp->transaction_id,&temp->amt);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}

int length()
{
    struct node* temp;
    int count=0;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void display()
{
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
    while(temp!=NULL)
    {
        printf("\nName->%s Transaction ID->%d Amount->%d",temp->name,temp->transaction_id,temp->amt);
        temp=temp->link;
    }
    }
}
void addatafter(void)
{

}
void addatbegin(void)
{

}
void del(void)
{

}
void main()
{
    int ch;
    printf("\nTHE LINKED LIST\n");
    while(1)
    {

        printf("\n1.Add at end\t");
        printf("2.Add at begin\t");
        printf("3.Add at after\t");
        printf("4.Count the nodes\t");
        printf("5.Display\t");
        printf("6.Delete\t");
        printf("7.Exit");
        printf("\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:append();
                   break;
            case 2:addatbegin();
                   break;
            case 3:addatafter();
                   break;
            case 4:len=length();
                   printf("\nThe number of the nodes is %d",len);
                   break;
            case 5:display();
                   break;
            case 6:del();
                   break;
            case 7:exit(0);

            default :printf("\nThe choice is invalid");
        }

    }
}


