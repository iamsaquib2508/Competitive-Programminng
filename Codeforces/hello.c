#include<stdio.h>

int leapyearcheck(int year)
{
    if(year%4>0)
    {
        printf("not leapyear\n");
    }
    else if(year%100>0)
    {
        printf("leapyear\n");
    }
    else if(year%400>0)
    {
        printf("not leapyear\n");
    }
    else
    {
        printf("leapyear\n");
    }
    return 0;
}

int main()
{
    int year;
    scanf("%d", &year);
    leapyearcheck(year);

    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);

    int year2;
    scanf("%d", &year2);
    leapyearcheck(year2);

    return 0;
}
