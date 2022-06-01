#include"dayofdate.h"
#include<stdio.h>

int main()
{
    int day=18, month=03, year=2022,wdayno;
    char dayNames[][12] = { "Monday", "Tuesday",
    "Wednesday","Thursday", "Friday", "Saturday", "Sunday" };
    //input date
   // printf("Input date (DD-MM-YYYY): ");
   // scanf("%d-%d-%d", &day, &month, &year);
    wdayno=checkday(day,month,year);
    if(wdayno>=0)
        printf("week day is: %s\n", dayNames[wdayno]);
    else
        printf("Date is in-correct.\n");

    return 0;
}
