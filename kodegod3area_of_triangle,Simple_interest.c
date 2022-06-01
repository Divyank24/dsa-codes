//Area of triangle
/*#include<stdio.h>
main()
{
    float b,h,area;
    printf("Enter the base and height of triangle");
    scanf("%f%f",&b,&h);
    area=0.5*b*h;
    printf("Answer is:%0.2f",area);

}*/
//Simple Interest
#include<stdio.h>
main()
{
    float P,T,R,SI;
    printf("Enter the principal amt, time, rate of interest\n");
    scanf("%f%f%f",&P,&T,&R);
    SI=P*T*R;
    printf("%f",SI);
}
