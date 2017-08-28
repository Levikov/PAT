#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
bool isValid(char *a,int n)
{
    int cnt =0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])cnt++;
        if(cnt>1)return false;
    }
    return true;    
}

int main()
{
    string s;
    cin>>s;
    vector<char> v;
    char *p=(char *)s.c_str();
    int N = strlen(p);
    for(int i=0;i<N;i++)
    {
        if(find(v.begin(),v.end(),p[i])==v.end())
        {
            v.push_back(p[i]);
            if(v.size()>2)
            {
                cout<<0;
                return 0;
            }
        }
    }
    cout<<v.size();
    return 0;
}
