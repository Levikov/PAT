#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long C1,C2,t;
    char h,m,s;
    cin>>C1>>C2;
    t=C2-C1;
    t=t/100+t%100/50;
    s=t%60;
    t=t/60;
    m=t%60;
    t=t/60;
    h=t%60;
    printf("%02d:%02d:%02d",h,m,s);

    return 0;
}