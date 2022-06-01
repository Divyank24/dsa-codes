//Program to perfor, different operations on given to numbers using functions(call by value)
/*#include<stdio.h>
#include<stdlib.h>
int add(int x,int y)
{
    printf("\n%d+%d=%d",x,y,x+y);
    return (x+y);

}
int diff(int x,int y)
{
             //printf("\n%d-%d=%d",x,y,(x-y));
             return (x-y);
}
int pro(int x,int y)
{
    printf("\n%d*%d=%d",x,y,(x*y));
}
int quo(int x,int y)
{
    printf("\n%d/%d=%d",x,y,(x/y));
}
int main()
{
    int a,b;
    printf("\nEnter the two numbers");
    scanf("%d%d",&a,&b);
    printf("\nThe sum of the two numbers is ");
    add(a,b);
    printf("\nDifference is %d ",diff(a,b));

    printf("\nThe products is");
    pro(a,b);
    printf("\nQuotient is");
    quo(a,b);
}*/


//Print factorial fibonacci and whether prime or not
/*#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int fact(int a)
{
    int fac=1;
    for(int i=1;i<=a;i++)
    {
        fac=fac*i;
        printf("\t%d",i);
    }
    return fac;
}
int prime(int a)
{
    for(int i=2;i<a;i++)
    {

        if(a%i==0)
        {

            return 0;
            break;

        }


    }
    return 1;



}
int fibo(int a)
{
    int pre=0,cur=1,temp,i;
    printf("\t%d\t%d",pre,cur);
    for(i=2;i<a;i++)
    {
        temp=cur;
        cur=cur+pre;
        pre=temp;
        printf("\t%d",cur);
    }
}
int main()
{
    int n,k;
    printf("\nEnter the number");
    scanf("%d",&n);
    printf("\nThe factorial value is %d",fact(n));
    printf("\n",prime(n));
    k=prime(n);
    if(k==0)
        printf("\n not prime");
    else
        printf("\n prime");
    printf("\nThe fibonacci series is");
    fibo(n);
}*/

//Cube and Square
#include<stdio.h>
cube(int a)
{
    printf("\nCube is %d*%d*%d=%d",a,a,a,a*a*a);
}
square(int a)
{
    printf("\nSquare is %d*%d=%d",a,a,a*a);
}
int main()
{
    int n;
    printf("\nEnter the number");
    scanf("%d",&n);
    square(n);
    cube(n);

}
