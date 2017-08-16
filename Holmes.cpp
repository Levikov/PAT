#include<iostream>
#include<stdio.h>
using namespace std;

inline void getFirst(string s1,string s2)
{
    char flag=0;
    char *p = (char *)s1.c_str();
    char *q = (char *)s2.c_str();
    const string t[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    while(*p&&*q)
    {
        if(*p==*q&&*q>='A'&&*q<='G'&&flag==0)
        {
            cout<<t[*p-'A']<<" ";
            flag++;
        }
        else if(*p==*q&&(*q>='A'&&*q<='N'||*q>='0'&&*q<='9')&&flag==1)
        {
            (*q>='A')?printf("%02d:",*q-'A'+10):printf("%02d:",*q-'0');
            return;
        }
        p++;
        q++;
    }
}
inline void getSecond(string s1,string s2)
{
    char flag=0;
    char *p = (char *)s1.c_str();
    char *q = (char *)s2.c_str();
    while(*p&&*q)
    {
        if(*p==*q&&(*q>='A'&&*q<='Z'||*q>='a'&&*q<='z'))
        {
            printf("%02d",flag);
            return;
        }
        p++;
        q++;
        flag++;
    }
}

int main()
{
    string s[4];
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    cin>>s[3];
    getFirst(s[0],s[1]);
    getSecond(s[2],s[3]);
    return 0;
}