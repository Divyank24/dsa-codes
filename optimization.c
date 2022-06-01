//DEAD CODE ELIMIINATION
#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end;
    double t;
    int i,y;
    printf("\nValue for and y:");
    scanf("%d",&y);

    start =clock();
    for(i=0;i<y;i++)
        printf("%d ",i);
    end=clock();

    t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n%lf",t);
    return 0;
}

