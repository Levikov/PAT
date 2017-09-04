#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int p,N;
    cin>>N>>p;
    int a[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    sort(a,a+N);
    int max=0;
    for(int i=0;i<N;i++)
    {
        if(N-i<max)break;
        for(int j=i;j<N;j++)
        {
            if(a[j]<=a[i]*p)
            {
                max=j-i+1>max?j-i+1:max;
            }else
            break;
        }
    }
    cout<<max;
    

}