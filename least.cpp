#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int N[10],max=10,maxidx=0;
    string o = "";
    for(int i=0;i<10;i++)
    {
        cin>>N[i];
        if(i<max&&i!=0&&N[i]!=0){max=i;maxidx=i;};
    }
    N[maxidx]--;
    o+=string(1,maxidx+'0');
    for(int i=0;i<10;i++)
    {
        while(N[i]--)
        {
            o+=string(1,i+'0');
        }
    }
    cout<<o;


}