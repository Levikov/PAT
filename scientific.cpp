#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    string s;
    char* digit;
    char sign1;
    char sign2;
    int coef;
    cin>>s;
    char *p = (char *)s.c_str();
    sscanf(p,"%c%sE%c%d",&sign1,digit,&sign2,&coef);
    return 0;
}