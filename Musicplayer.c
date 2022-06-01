//MENU BASED MUSIC PLAYER PROGRAM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[10];
    char sname[10];
    char mname[10];        //CREATE A STRUCTURE FOR THE MUSIC PLAYER WHICH INCLUDES
    float dur;             //SONG NAME,SINGER NAME,MOVIE NAME,YEAR OF RELEASE,DURATION
    int year;
    struct node *prev;     //2 POINTERS
    struct node *next;
};

struct node *head;  //HEAD POINTER TO DENOTE THE STARTING ADHHRESS IN THE QUEUE OF SONGS
int l;              //GLOBAL DECLARARTION OF VARIALE TO STORE THE COUNT OF SONGS
int length()
{
    struct node *temp;
    int count=0;
    if(head==0)
        printf("\nEmpty list");          //FUNCTION TO COUNT THE NUMBER OF SONGS IN THE PLAYLIST
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
    printf("\nSONG_NAME:");
    scanf("%s",newn->name);
    printf("SINGER_NAME:");                //FUNCTION TO CREATE THE PLAYLIST
    scanf("%s",newn->sname);
    printf("MOVIE_NAME:");
    scanf("%s",newn->mname);
    printf("DURATION(MINS):");
    scanf("%f",&newn->dur);
    printf("YEAR_OF_RELEASE:");
    scanf("%d",&newn->year);

    newn->prev=0;
    newn->next=0;

    if(head==0)
    {
        head=newn;              //IF EMPTY LIST SONG ADDED IS THE FIRST SONG
    }
    else
    {
        temp=head;
        while(temp->next!=0)    //ELSE TRAVERSE TILL THE LAST SONG AND ADD NEW SONG
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
        printf("\nThe list is empty");      //IF THE SONG LIST IS EMPTY
    else
    {
        printf("\n*****THE PLAYLIST*****\n");
        temp=head;         //TEMP POINTER TO DISPLAY ALL THE SONGS
        while(temp!=NULL)
        {

            printf("\n->SONG _NAME:%s",temp->name);      //FUNCTION TO DISPLAY THE CREATED PLAYLIST
            printf("\nSINGER_NAME:%s",temp->sname);
            printf("\nMOVIE_NAME:%s",temp->mname);
            printf("\nDUARTION(MINS):%.2f",temp->dur);
            printf("\nYEAR:%d\n",temp->year);
            temp=temp->next;
        }
    }
}

void insert_end()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the details");
    printf("\nSONG_NAME:");
    scanf("%s",newn->name);
    printf("SINGER_NAME:");
    scanf("%s",newn->sname);
    printf("MOVIE_NAME:");                   //FUNCTION TO ADD SONG TO THE QUEUE
    scanf("%s",newn->mname);
    printf("DURATION(MINS):");
    scanf("%f",&newn->dur);
    printf("YEAR_OF_RELEASE:");
    scanf("%d",&newn->year);
    newn->next=0;
    newn->prev=0;

    if(head==0)
    {                                                   //IF EMPTY LIST SONG ADDED IS THE FIRST SONG
        head=newn;
    }
    else                                             //ELSE TRAVERSE TILL THE LAST SONG AND ADD NEW SONG
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
    printf("\nSONG_NAME:");
    scanf("%s",newn->name);                           //FUNCTION TO INSERT THE SONG AT THE BEGINNING
    printf("SINGER_NAME:");
    scanf("%s",newn->sname);
    printf("MOVIE_NAME:");
    scanf("%s",newn->mname);
    printf("DURATION(MINS):");
    scanf("%f",&newn->dur);
    printf("YEAR_OF_RELEASE:");
    scanf("%d",&newn->year);
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
    printf("\nEnter the year to be searched=");      //FUNCTION TO SEARCH THE SONG BY YEAR
    scanf("%d",&y);
    if(head==0)
        printf("\nNo songs to search");      //IF EMPTY LIST
    else
    {
        temp=head;
    while(temp!=0)
    {
        if(temp->year==y)            //COMPARES YEAR EACH SONG WITH THE DESIRED YEAR
        {
            flag=1;
            printf("\nThe search is successful\n");
         printf("%s %s %s %f %d",temp->name,temp->sname,temp->mname,temp->dur,temp->year); //DISPLAYS THE SONG IF SEARCH IS SUCCESSFUL
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
    scanf("%s",sname);                              //FUNCTION TO SEARCH THE SONG BY NAME OF THE SONG
    if(head==0)
    {
        printf("\n NO songs to compare");
    }

    else
    {
        int flag=0;
        temp=head;
        while(temp!=0)
        {
        if(strcmp(temp->name,sname)==0)
        {
            flag=1;              //FLAG VARIBE IF 1 THEN SONG IS FOUND
            printf("\nThe search is successful\n");
            printf("%s %s %s %f %d",temp->name,temp->sname,temp->mname,temp->dur,temp->year);               //DISPLAYS THE SONG IF SEARCH IS SUCCESSFUL
        }
        temp=temp->next;
      }
     if(flag==0)
        printf("Not found"); //FLAG =0 NO SUCH SONGS
    }
}

void del_end()
{
    struct node *temp,*back;

    if(head==0)
        printf("\nNo songs to delete");
    else                                               //FUNCTION TO DEQUEUE THE SONG FROM THE PLAYLIST
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
        printf("\nNo songs to delete");
    else
    {
        temp=head;                             //FUNCTION TO DEQUEUE THE SONG FROM THE PLAYLIST

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
        printf("\nNo songs are present");
                                                              //FUNCTION TO INSERT SONG AT DESIRED LOCATION
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
           printf("\nSONG_NAME:");
            scanf("%s",newn->name);
            printf("SINGER_NAME:");
            scanf("%s",newn->sname);
            printf("MOVIE_NAME:");
            scanf("%s",newn->mname);
            printf("DURATION:");
            scanf("%f",&newn->dur);
            printf("YEAR_OF_RELEASE:");
            scanf("%d",&newn->year);
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

    if(head==0)                                 //FUNCTION TO INSERT SONG AFTER THE DESIRED LOCATION
        printf("\nNo songs are present");
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
            insert_end();  //LACTION ENTERED IS EQUAL TO LENGTH OF THE LIST FUNCTION INSERT END IS CALLED
        }
        else
        {
            temp=head;
            newn=(struct node*)malloc(sizeof(struct node));
            printf("Enter the details");
            printf("\nSONG_NAME:");
            scanf("%s",newn->name);
            printf("SINGER_NAME:");
            scanf("%s",newn->sname);
            printf("MOVIE_NAME:");
            scanf("%s",newn->mname);
            printf("DURATION:");
            scanf("%f",&newn->dur);
            printf("YEAR_OF_RELEASE:");
            scanf("%d",&newn->year);
            newn->next=0;
            newn->prev=0;

            while(i<loc)
            {
                temp=temp->next;
                i++;
            }
            front=temp->next;

            newn->next=temp->next;  //LOGIC TO INSERT SONG AT THE DESIRED LOCATION
            newn->prev=temp;
            temp->next=newn;
            front->prev=newn;

        }
    }
}
void del_at_loc()
{
    struct node *temp,*front,*back;
    int i=1,loc;                                    //FUNCTION TO DELETE THE SONG AT DESIRED POSITION

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
           del_front();  //DELETE FRONT FUNCTION IS CALLED
        else if(loc==length())
            del_end();  //DELETE END FUNCTION IS CALLED
        else
        {
            while(i<loc)
            {
                temp=temp->next;
                i++;
            }
            front=temp->next;
            back=temp->prev;
            back->next=temp->next;      //LOGIC TO DELETE THE SONG AT THE DESIRED LOCATION
            front->prev=back;
            temp->next=0;
            temp->prev=0;
            free(temp);

        }

    }
}

struct node* insert_speci()
{
    struct node *temp,*newn,*front;
    char sn[20];
    if(head==0)
    {
        printf("\nNo songs are present in the list");
        return NULL;
    }
    else
    {
        temp=head;
        printf("\nEnter the song to be inserted\n");
        scanf("%s",sn);
        newn=(struct node*)malloc(sizeof(struct node));
        printf("Enter the details");
        printf("\nSONG_NAME:");
        scanf("%s",newn->name);
        printf("SINGER_NAME:");
        scanf("%s",newn->sname);
        printf("MOVIE_NAME:");
        scanf("%s",newn->mname);
        printf("DURATION(MINS):");
        scanf("%f",&newn->dur);
        printf("YEAR_OF_RELEASE:");
        scanf("%d",&newn->year);
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
        printf("\nNo songs present in the list");
        return head;
    }

}

void main()
{
    int ch;
    while(1)
    {
    printf("\n\n*********MUSIC PLAYER**********\n*****MENU*****\n->1.CREATE PLAYLIST. \n->2.DISPLAY. \n->3.ADD TO QUEUE. \n->4.SEARCH  \n->5.DEQUEUE SONG \n->6.SEARCH(by year) \n->7.NUMBER OF SONGS IN PLAYLIST \n->8.ADD SONG AT PARTICULAR POSITION(at)  \n->9.INSERT AFTER PARTICULAR SONG \n->10.DELETE PARTICULAR SONG(at location) \n->11.Exit");
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
        case 4:search();
               break;
        case 5:del_front();
               break;
        case 6:search_by_year();
               break;
        case 7:l=length();
                printf("\nThe number of songs in the play list are %d",l);
                break;
        case 8:insert_at_loc();
                break;
        case 9:insert_speci();
                break;
        case 10:del_at_loc();
                break;
        case 11:exit(0);
               break;
        default:printf("\nInvalid choice");
               break;
     }
  }
}

