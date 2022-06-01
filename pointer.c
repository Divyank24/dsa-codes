#include<stdio.h>
#include<stdlib.h>


void add(int* p,int* p1)
{
    //int m;
    //int *c=&m;
    *p=*p + *p1;

}
int main()
{
    int a,b;
    //int* p=&a;
    //int* p1=&b;
    printf("\nEnter the numbers to be added");
    scanf("\n%d %d",&a,&b);
    add(&a,&b);
    printf("\nThe answer is %d",a);
    return 0;

}


