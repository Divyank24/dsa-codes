#include<stdio.h>
typedef struct recharge
{
    char name[100], type[100];
    float money;
}MBL;
typedef struct hotel_booking
{
    char name[100], place[100];
    int days;
    float amt;
}HBK;
typedef struct PhoneTM
{
    MBL recharge;
    HBK hotel;
}PTM;
void read(PTM c[100], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
    printf("\nEnter the money spent on %d recharge: 1.Service Provider Name\t2.Mobile(Data/Topup)\t3.Cost\nHotel booking:1.HotelName\t2.Place\t3.Days\t4.Amountt\n", i+1);
    scanf("%s%s%f%s%s%d%f", c[i].recharge.name, c[i].recharge.type, &c[i].recharge.money, c[i].hotel.name, c[i].hotel.place, &c[i].hotel.days, &c[i].hotel.amt);
    }
}
void display(PTM c[100], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
       printf("\n%d.Recharge\n",i+1);
       printf("Service Provider Name\tMobile(Data/Topup)\tCost\n");
       printf("%s\t\t%s\t\t%0.2f\n", c[i].recharge.name, c[i].recharge.type, c[i].recharge.money);
    }
    for (i=0;i<n;i++)
    {
        printf("\n.Hotel Booking\n");
        printf("HotelName\t\tPlace\t\tDays\t\tAmount\n");
        printf("%s\t%s\t%d\t%0.2f\n", c[i].hotel.name, c[i].hotel.place, c[i].hotel.days, c[i].hotel.amt);
    }
}
void total_recharge(PTM c[100], int n)
{
    int i;
    float s=0;
    for(i=0;i<n;i++)
    {
        s=s+c[i].recharge.money;
    }
    printf("\nTotal Money spent on recharge:%0.2f", s);
}
void highest_transaction(PTM c[100], int n)
{
    int i,j,k,s=0,t=0,u=0;
    float d=0,b=0,p=0;
    for (i=0;i<n;i++)
    {
        if(c[i].recharge.money>b)
        {
            b=c[i].recharge.money;
            s=i;
        }
    }
    for(j=0;j<n;j++)
    {
        if(c[j].hotel.amt>p)
        {
            p=c[j].hotel.amt;
            t=j;
        }
    }

    if(b>=p&&b>=d)
    {
        printf("\nHighest transaction is for %d recharge\n",s);
        printf("Mobile\t\t\n");
        printf("%s\t\t%s\t\t%0.2f\n", c[s].recharge.name, c[s].recharge.type, c[s].recharge.money);
    }
    else if(p>=b&&p>=d)
    {
        printf("\nHighest transaction is for %d hotel booking\n",t);
        printf("HotelName\t\tPlace\t\tDays\t\tAmount\n");
        printf("%s\t%s\t%d\t%0.2f\n", c[t].hotel.name, c[t].hotel.place, c[t].hotel.days, c[t].hotel.amt);
    }


}
void main()
{
    int n;
    PTM c[100];
    printf("Enter the number of transactions:");
    scanf("%d", &n);
    read(c,n);
    display(c,n);
    total_recharge(c,n);
    highest_transaction(c,n);
}
