#include <stdio.h>
#include<time.h>

int main()

{

    int unit;
    float t;
    float amt;

    while (1)

    {

        printf("\nEnter total units consumed :");

        scanf(" %d", &unit);

        if (unit > 0 && unit <= 100)

        {

            amt = unit * 1.5;

        }

        else if (unit > 100 && unit <= 250)

        {

            amt = 100 * 1.5 + (unit - 100) * 2.3;

        }

        else if (unit > 250 && unit <= 600)

        {

            amt = 100 * 1.5 + 250 * 2.3 + (unit - 250) * 4.0;

        }

        else if (unit > 600)

        {

            amt = 1000;

        }
        else if(unit <0)
        {
            printf("\nInvalid\n");
            exit(0);
        }
        else
        {
            amt=0;
        }

        printf("Total Electricity bill is : %0.2f ", amt);
        t=clock();
        printf("\nThe time required for execution is %f",t/CLOCKS_PER_SEC);

}



    return 0;

}
