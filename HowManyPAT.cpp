#include<iostream>
using namespace std;

int main()
{
    string s;
    int p=0,pa=0,pat=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i)=='P')p++;
        else if(s.at(i)=='A')
        {
            pa+=p;
            pa=pa%1000000007;
        }else
        {
            pat+=pa;
            pat = pat%1000000007;
        }
    }
    cout<<pat;
}