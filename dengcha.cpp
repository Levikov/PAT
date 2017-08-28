#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int N;
    vector<int> v;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    int d = v[1]-v[0];
    for(int i=0;i<N-1;i++)
    {
        if(v[i+1]-v[i]!=d)
        {
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible";
    return 0;
    
}