#include<stdio.h>
#include<stdlib.h>
typedef struct trans
{
  int no,amt;
  char place[20];
}tran;

void read(FILE *fp,tran *t,int n)
{
    int i;
   for(i=0;i<n;i++)
    {
         printf("Enter customer %d details :\n",i+1);
         printf("Enter Transaction no.\tDestination\t amount\n");
         scanf("%d%s%d",&(t+i)->no,(t+i)->place,&(t+i)->amt);
         fprintf(fp,"%d%s%d",&(t+i)->no,(t+i)->place,&(t+i)->amt);
    }
}
void display(FILE *fp,tran *t,int n)
{
   int i;
   printf("\nDetails :\n");
   printf("Transaction no.\tDestination\t amount\n");
       for(i=0;i<n;i++)
       {
              fscanf(fp,"%d%s%d",(t+i)->no,(t+i)->place,(t+i)->amt);
              printf("%d\t\t%s\t\t%d\n",(t+i)->no,(t+i)->place,(t+i)->amt);
       }
}
void disc(FILE *fp,tran *t,int n)
{
    int i;
    int a=0;
    printf("\nThe customer who gets the discount are :\n");
       printf("Transaction no.\tDestination\t amount\n");
    for(i=0;i<n;i++)
    {
         fscanf(fp,"%d%s%d",(t+i)->no,(t+i)->place,(t+i)->amt);
            if(((t+i)->no)%25==0)
        {
          printf("%d\t\t%s\t\t%d\n",(t+i)->no,(t+i)->place,(t+i)->amt);
          a+=0.5*(t+i)->amt;
        }
    }
    printf("\nThe amount i.e is discounted = %d rs.",a);
}

void main()
{
    tran *t;
    FILE *fp;
    int n;
    printf("Enter the no. of transactions\n");
    scanf("%d",&n);
    t=calloc(n,sizeof(tran));
    fp=fopen("train.txt","w");
    read(fp,t,n);
    fclose(fp);
    fp=fopen("train.txt","w");
    display(fp,t,n);
    fclose(fp);
    fp=fopen("train.txt","w");
    disc(fp,t,n);
    fclose(fp);
    free(t);
}
