#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void replaceSpace(char *str,int length) {
    int N=length;
    for(int i=0;i<length;i++)
    {
        if(*(str+i)==' ')N=N+2;
    }
    char *r = (char *)malloc(N+1);
    str = (char *)malloc(N+1);
    r[N]='\0';
    char *p=r;
    for(int i=0;i<length;i++)
    {
        if(*(str+i)==' ')
        {
            *(p++)='%';
            *(p++)='2';
            *(p++)='0';
            
        }
        else
        {
            *(p++)=*(str+i);
        }
    }
    strcpy(str,r);
}

void main()
{
    char *s =malloc(12);
    s ="hellow world";
    replaceSpace(s,11);
    printf("%s",s);    
}