#include<stdio.h>
#include<math.h>
typedef struct axis_D
{
    int x,y;
}D;
D read(D p1);
void display(D pt1,D pt2);
void displayqu(D pt1);
void main()
{
    D pt1,pt2;
    pt1=read(pt1);
    pt2=read(pt2);
    displayqu(pt1);
    displayqu(pt2);
    display(pt1,pt2);
}
D read(D pt1)
{
    printf("Enter the x and y respectively:: ");
    scanf("%d %d",&pt1.x,&pt1.y);
    return pt1;
}
void displayqu(D pt1)
{
    printf("%d %d\n",pt1.x,pt1.y);
    if(pt1.x>0&&pt1.y>0)
        printf("Point lies in 1st quadrant\n");
    else if(pt1.x>0&&pt1.y<0)
        printf("Point lies in 4th quadrant\n");
    else if(pt1.x<0&&pt1.y>0)
        printf("Point lies in 2nd quadrant\n");
    else if(pt1.x<0&&pt1.y<0)
        printf("Point lies in 3rd quadrant\n");
}
void display(D pt1,D pt2)
{
    float dist,m,a,b;
    dist=sqrt((pow((pt2.x-pt1.x),2))+pow((pt2.y-pt1.y),2));
    a=(pt2.y-pt1.y);
    b=(pt2.x-pt1.x);
    m=a/b;
    printf("Distance between points %f\nSlope between points %f",dist,m);
}
