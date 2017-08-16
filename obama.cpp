#include<iostream>
using namespace std;
inline void head(int n,char c)
{
    while(n--)cout<<c;
    cout<<endl;
}
inline void body(int n,char c)
{
    n = n-2;
    cout<<c;
    while(n--)cout<<" ";
    cout<<c<<endl;
}

int main()
{
    int N,H;
    char c;
    cin>>N>>c;
    H = N/2 + N%2 -2;
    head(N,c);
    while(H--)body(N,c);
    head(N,c);
}