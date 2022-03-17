#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;




void delete_at_position(int x)
{
    struct node *temp=head;
    for(int i=2; i< x; i++)
        {

            temp = temp->next;

        }

temp->next = temp->next->next;
}
void create_list (int n)
{
    struct node *newnode,*temp;
        head=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("enter data:\n");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;
    for(int i=1;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("memory not allocated:");
            exit(0);
        }
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void main()
{
    int n,x;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    create_list(n);
    printf("the created list:\n");
    display();
    printf("enter the location to delete:");
    scanf("%d",&x);
    delete_at_position(x);
    printf("the list after insertion at position is:\n");
    display();
}
