#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int cnt(vector<int> v,int g)
{
    int r=0;
    vector<int>::iterator p = v.begin();
    while(p<v.end())
    {
        if(*p==g)r++;
        p++;
    }
    return r;
}

int main()
{
    int N;
    int c;
    vector<int> v;
    cin>>N;
    while(N--)
    {
        cin>>c;
        v.push_back(c);
    };
    cin>>N;
    while(N--)
    {
        cin>>c;
        (N==0)?cout<<cnt(v,c):cout<<cnt(v,c)<<" ";
    }


    return 0;
}