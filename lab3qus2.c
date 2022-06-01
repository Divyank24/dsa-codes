#include<stdio.h>
#include<string.h>
typedef struct shopping
{
    char mbl_name[20];
    char model_mbl[20];
    int RAM;
    int memory;
    float cost;
    int year_release;
}shop;

void read_from_user(FILE *fp)
{
 shop s;
 int i,n;
 printf("enter number of phones\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
      printf("Enter MobileName,Model ,ram ,internal memory, cost and year of release\n");
      scanf("%s%s%d%d%f%d",s.mbl_name,s.model_mbl,&s.RAM,&s.memory,&s.cost,&s.year_release);
      fprintf(fp,"%s %s %d %d %f %d\n",s.mbl_name,s.model_mbl,s.RAM,s.memory,s.cost,s.year_release);
 }
}
void read_from_file(FILE *fp)
{
    shop s;
   printf("Mobile Name\tModel\tram\tinternal memory\tcost\t year of release\n");
    while(!feof(fp))
    {
         fscanf(fp,"%s%s%d%d%f%d\n",s.mbl_name,s.model_mbl,&s.RAM,&s.memory,&s.cost,&s.year_release);
          printf("%s\t\t%s\t%d\t%d\t%f\t%d\n",s.mbl_name,s.model_mbl,s.RAM,s.memory,s.cost,s.year_release);
    }
}
void lowest_price(FILE *fp,int n)
{
    shop s;
    int i,j;
    int low=99999;
for(i=1;i<=n;i++)
 {
    if(s.cost<low)
     {
      low=s.cost;
      j=i;
     }
 }
 printf("\n\nMobile with lowest price : \n");
 fscanf(fp,"%s%s%d%d%d%d",s.mbl_name,s.model_mbl,&s.RAM,&s.memory,&s.cost,&s.year_release);
printf("%s\t\t%s\t\t%d\t%d\t\t%d\t\t%d\n",s.mbl_name,s.model_mbl,s.RAM,s.memory,s.cost,s.year_release);
}
void display_from_file(FILE *fp)
{
  shop s;
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d%d%f%d\n",s.mbl_name,s.model_mbl,&s.RAM,&s.memory,&s.cost,&s.year_release);

         if(s.year_release>=2020)
         {
           printf("\nNewest mobile launched are as follows :\n");
           printf("%s\t\t%s\t%d\t%d\t%f\t%d\n",s.mbl_name,s.model_mbl,s.RAM,s.memory,s.cost,s.year_release);
         }

         }
    }


int main()
{
    int n;
 FILE *fp;
 fp=fopen("smartphone.txt","w");
 read_from_user(fp);
 fclose(fp);
  fp=fopen("smartphone.txt","r");
 read_from_file(fp);
 fclose(fp);
 fp=fopen("smartphone.txt","r");
 display_from_file(fp);
 lowest_price(fp,n);
 fclose(fp);
 return 0;
}
