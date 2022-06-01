//MULTIPLE OR DIVISIBLE BY A NUMBER
/*#include<stdio.h>
main()
{
    int a;
    printf("\nEnter the number:");
    scanf("%d",&a);
    if(a%5==0)
        printf("\nThe number s divsible or multiple of 5");
    else
        printf("\nThe number is not a divisible or multiple of 5");
}*/

#include<stdio.h>
main()
{
    int a,b;
    printf("\nEnter the two numbers\n");
    scanf("%d%d",&a,&b);
    if(a%b==0)
        printf("\n%d is divisible by %d",a,b);
    else if(b%a==0)
        printf("\n%d is divisible by %d",b,a);
    else
        printf("\nInvalid");
}
