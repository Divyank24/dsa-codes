#include<stdio.h>
typedef struct recharge
{
    char name[100], type[100];
    float money;
}MBL;
typedef struct hotel_booking
{
    char name[100], location[100];
    int days;
    float cost;
}HBK;
typedef struct PhoneTM
{
    MBL recharge;
    HBK hotel;
}PTM;
void read(PTM a[100], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
    printf("\nEnter the money spent on %d recharge: 1.Name\t2.Mobile-Telephone\t3.Cost\nHotel booking:1.Name\t2.Location\t3.Days\t4.Cost\n", i+1);
    scanf("%s%s%f%s%s%d%f", a[i].recharge.name, a[i].recharge.type, &a[i].recharge.money, a[i].hotel.name, a[i].hotel.location, &a[i].hotel.days, &a[i].hotel.cost);
    }
}
void display(PTM a[100], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
       printf("\n%d.Recharge\n",i+1);
       printf("Name\tMobile-Telephone\tCost\n");
       printf("%s\t\t%s\t\t%0.2f\n", a[i].recharge.name, a[i].recharge.type, a[i].recharge.money);
    }
    for (i=0;i<n;i++)
    {
        printf("\n%d.Hotel Booking\n");
        printf("Name\t\tLocation\t\tDays\t\tCost\n");
        printf("%s\t%s\t%d\t%0.2f\n", a[i].hotel.name, a[i].hotel.location, a[i].hotel.days, a[i].hotel.cost);
    }
}
void total_recharge(PTM a[100], int n)
{
    int i;
    float s=0;
    for(i=0;i<n;i++)
    {
        s=s+a[i].recharge.money;
    }
    printf("\nTotal Money spent on recharge:%0.2f", s);
}
void highest_transaction(PTM a[100], int n)
{
    int i,j,k,s=0,t=0,u=0;
    float d=0,b=0,c=0;
    for (i=0;i<n;i++)
    {
        if(a[i].recharge.money>b)
        {
            b=a[i].recharge.money;
            s=i;
        }
    }
    for(j=0;j<n;j++)
    {
        if(a[j].hotel.cost>c)
        {
            c=a[j].hotel.cost;
            t=j;
        }
    }

    if(b>=c&&b>=d)
    {
        printf("\nHighest transaction is for %d recharge\n",s);
        printf("Mobile\t\tTelephone\n");
        printf("%s\t\t%s\t\t%0.2f\n", a[s].recharge.name, a[s].recharge.type, a[s].rech.money);
    }
    else if(c>=b&&c>=d)
    {
        printf("\nHighest transaction is for %d hotel booking\n",t);
        printf("Name\t\tLocation\t\tDays\t\tCost\n");
        printf("%s\t%s\t%d\t%0.2f\n", a[t].hotel.name, a[t].hotel.location, a[t].hotel.days, a[t].hotel.cost);
    }


}
void main()
{
    int n;
    PTM a[100];
    printf("Enter the number of transactions:");
    scanf("%d", &n);
    read(a,n);
    display(a,n);
    total_recharge(a,n);
    highest_transaction(a,n);
}
