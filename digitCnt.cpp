#include<iostream>
using namespace std;

int main()
{
    int cnt[10]={0,0,0,0,0,0,0,0,0,0};
    string N;
    cin>>N;
    char *p = (char *)N.c_str();
    while(*p){
        cnt[(*(p++)-'0')%10]++;
    };
    for(int i=0;i<10;i++)
    if(cnt[i]!=0)cout<<i<<":"<<cnt[i]<<endl;
    return 0;
}