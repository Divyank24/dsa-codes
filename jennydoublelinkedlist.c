//MENU BASED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[10];
    char mname[10];
    int year;
    struct node *prev;
    struct node *next;
};

struct node *head;
int l;
int length()
{
    struct node *temp;
    int count=0;
    if(head==0)
        printf("\nEmpty list");
    else
    {
        temp=head;
        while(temp!=0)
        {
            temp=temp->next;
            count ++;
        }
    }
    return count;
}
void create()
{

    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nNAME(SONG) YEAR_OF_RELEASE\n");
    scanf("%s %d",newn->name,&newn->year);
    newn->prev=0;
    newn->next=0;

    if(head==0)
    {
        head=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
        temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void display()
{
    struct node *temp;
    if(head==0)
        printf("\nThe list is empty");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("\n%s %d",temp->name,temp->year);
            temp=temp->next;
        }
    }
}

void display_lasttofirst()
{
    struct node *temp;
    if(head==0)
        printf("\nEmpty list");
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }

        while(temp!=0)
        {
            printf("\n%s %d",temp->name,temp->year);
            temp=temp->prev;
        }
    }
}

void insert_end()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nNAME(SONG) YEAR OF RELEASE\n");
    scanf("%s %d",newn->name,&newn->year);
    newn->next=0;
    newn->prev=0;

    if(head==0)
    {
        head=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void insert_begin()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nNAME(SONG) YEAR OF RELEASE\n");
    scanf("%s %d",newn->name,&newn->year);
    newn->next=0;
    newn->prev=0;

    if(head==NULL)
    {
        head=newn;
    }

    else
    {
        temp=head;
        head->prev=newn;
        newn->next=head;
        head=newn;
    }

}
void search_by_year()
{
    struct node *temp;
    int y,flag=0;
    printf("\nEnter the year to be searched=");
    scanf("%d",&y);
    if(head==0)
        printf("\nNo nodes to search");
    else
    {
        temp=head;
    while(temp!=0)
    {
        if(temp->year==y)
        {
            flag=1;
         printf("%s %d",temp->name,temp->year);
        }
        temp=temp->next;
    }
    if(flag==0)
        printf("\nSearch not found");

 }
}

void search()
{
    struct node *temp;
    char sname[10];
    printf("\nEnter the name to search=");
    scanf("%s",sname);
    if(head==0)
    {
        printf("\n NO nodes to compare");
    }

    else
    {
        int flag=0;
        temp=head;
        while(temp!=0)
        {
        if(strcmp(temp->name,sname)==0)
        {
            flag=1;
            printf("%s %d",temp->name,temp->year);
        }
        temp=temp->next;
      }
     if(flag==0)
        printf("Not found");
    }
}

void del_end()
{
    struct node *temp,*back;

    if(head==0)
        printf("\nNo nodes to delete");
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            back=temp;
            temp=temp->next;
        }
        back->next=0;
        temp->prev=0;
        free(temp);
    }
}

void del_front()
{
    struct node *temp;

    if(head==0)
        printf("\nNo nodes to delete");
    else
    {
        temp=head;

        head=head->next;
        head->prev=0;
        temp->next=0;
        free(temp);
    }
}


void insert_at_loc()
{
    struct node *newn,*temp,*front;
    int i=1,loc;

    if(head==0)
        printf("\nNo nodes are present");

    else
    {
        printf("\nEnter the location at which the node is to be inserted=");
        scanf("%d",&loc);

        if(loc==1)
        {
            insert_begin();
        }
        else if(loc<1||loc>length())
        {
            printf("\nInvalid input location");
        }
        else
        {
            temp=head;
            newn=(struct node*)malloc(sizeof(struct node));
            printf("Enter the details");
            printf("\nNAME(SONG) YEAR OF RELEASE\n");
            scanf("%s %d",newn->name,&newn->year);
            newn->next=0;
            newn->prev=0;
            while(i<loc-1)
            {
                temp=temp->next;
                i++;
            }
            front=temp->next;


            newn->next=temp->next;
            newn->prev=temp;
            temp->next=newn;
            front->prev=newn;

        }

    }
}
void insert_after_loc()
{
    struct node *temp,*newn,*front;
    int loc,i=1;

    if(head==0)
        printf("\nNo nodes are present");
    else
    {
        printf("\nEnter the location after which insertion has to be performed=");
        scanf("%d",&loc);
        if(loc<1||loc>length())
        {
            printf("\nInvalid input location");
        }
        else if(loc==length())
        {
            insert_end();
        }
        else
        {
            temp=head;
            newn=(struct node*)malloc(sizeof(struct node));
            printf("Enter the details");
            printf("\nNAME(SONG) YEAR OF RELEASE\n");
            scanf("%s %d",newn->name,&newn->year);
            newn->next=0;
            newn->prev=0;

            while(i<loc)
            {
                temp=temp->next;
                i++;
            }
            front=temp->next;

            newn->next=temp->next;
            newn->prev=temp;
            temp->next=newn;
            front->prev=newn;

        }
    }
}
void del_at_loc()
{
    struct node *temp,*front,*back;
    int i=1,loc;

    if(head==0)
        printf("\nEmpty list");
    else if(head->next==0)
    {
        temp=head;
        head=0;
        printf("\nNo songs remain");
        free(temp);
    }
    else
    {
        temp=head;
        printf("\nEnter the location to be deleted\n");
        scanf("%d",&loc);

        if(loc<1 || loc>length())
            printf("\nInvalid input location");
        else if(loc==1)
           del_front();
        else if(loc==length())
            del_end();
        else
        {
            while(i<loc-1)
            {
                temp=temp->next;
                i++;
            }
            front=temp->next;
            back=temp->prev;
            back->next=temp->next;
            front->prev=back;
            temp->next=0;
            temp->prev=0;
            free(temp);

        }

    }
}

void del_after_loc()
{
    struct node *temp,*front,*cur;
    int loc,i=1;
    if(head==0)
        printf("\nEmpty list");
    else
    {
        temp=head;
        printf("\nEnter the location after which the node has to be deleted\n");
        scanf("%d",&loc);

        if(loc<1 || loc>length())
            printf("\nInvalid input location");
        else
        {
            while(i<loc)
            {
            cur=temp->next;
            front=cur->next;
            temp->next=cur->next;
            front->prev=cur->prev;
            cur->prev=0;
            cur->next=0;
            free(cur);
            }
        }
    }
}

struct node* insert_speci()
{
    struct node *temp,*newn,*front;
    char sn[20];
    if(head==0)
    {
        printf("\nNo nodes are present in the list");
        return NULL;
    }
    else
    {
        temp=head;
        printf("\nEnter the song to be inserted\n");
        scanf("%s",sn);
        newn=(struct node*)malloc(sizeof(struct node));
        printf("Enter the details");
        printf("\nNAME(SONG) YEAR OF RELEASE\n");
        scanf("%s %d",newn->name,&newn->year);
        newn->next=0;
        newn->prev=0;


        while(temp!=0)
        {
         if(strcmp(temp->name,sn)==0)
            {
                if(temp==head&&temp->next==NULL)
                {
                    temp->next=newn;
                    newn->prev=temp;
                    return head;
                }
                else if(temp==head)
                {
                    front=temp->next;
                    newn->next=front;
                    newn->prev=temp;
                    temp->next=newn;
                    front->prev=newn;
                    return head;

                }
                else if(temp->next==0)
                {
                    temp->next=newn;
                    newn->prev=temp;
                    return head;
                }
                else
                {
                    front=temp->next;
                    newn->next=front;
                    newn->prev=temp;
                    temp->next=newn;
                    front->prev=newn;
                    return head;
                }
            }
            temp=temp->next;
        }
        printf("\nNo nodes present in the list");
        return head;
    }

}
struct node* del_speci()
{
 struct node *temp,*front,*back;
 char sn[20];
 if(head==0)
 {
     printf("\nNo nodes are present in the list");
     return NULL;
 }
 else
 {
     temp=head;
     printf("\nEnter the song to be deleted");
     scanf("%s",sn);

     while(temp!=0)
     {
         if(strcmp(temp->name,sn)==0)
         {
             if(temp==head&&temp->next==0)
             {
                 head=0;
                 free(temp);
                 return NULL;
             }
             else if(temp==head)
             {
                 front=temp->next;
                 front->prev=0;
                 head=head->next;
                 temp->next=0;
                 free(temp);
                 return head;
             }
             else if(temp->next==0)
             {
                 back=temp->prev;
                 back->next=0;
                 temp->prev=0;
                 free(temp);
                 return head;
             }
             else
             {
                 front=temp->next;
                 back=temp->prev;
                 front->prev=back;
                 back->next=front;
                 temp->next=0;
                 temp->prev=0;
                 free(temp);
                 return head;

             }

         }
         temp=temp->next;
     }
     printf("\nNO nodes found in the list");
     return head;
 }


}

void main()
{
    int ch;
    while(1)
    {
    printf("\nMENU\n1.Create node 2.Display 3.Insert End 4.Insert begin 5. Search 6.Delete End 7.Delete Front 8.Display last to first \n9.Search(by year) 10.Length 11.Insert specific(at) 12.Insert specific(after) 13.Insert after particular song \n14.Delete particular song 15.Delete at(location) 16.Delete after(location) 17.Exit");
    printf("\nEnter the choice=");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:create();
               break;
        case 2:display();
               break;
        case 3:insert_end();
               break;
        case 4:insert_begin();
               break;
        case 5:search();
               break;
        case 6:del_end();
               break;
        case 7:del_front();
               break;
        case 8:display_lasttofirst();
               break;
        case 9:search_by_year();
               break;
        case 10:l=length();
                printf("\nThe length of the list is %d",l);
                break;
        case 11:insert_at_loc();
                break;
        case 12:insert_after_loc();
                break;
        case 13:insert_speci();
                break;
        case 14:del_speci();
                break;
        case 15:del_at_loc();
                break;
        case 16:del_after_loc();
                break;
        case 17:exit(0);
               break;
        default:printf("\nInvalid choice");
               break;
     }
  }
}
