#include<iostream>
#include<algorithm>
using namespace std;
bool isValid(int *a,int n,int k)
{
    int small=0,big=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])big++;
        else small++;

        if(small>k)return false;
        if(big>n-1-k)return false;
    }
    return true;
}

int main()
{
    int N,*a,k,cnt=0;
    cin>>N>>k;
    a = new int[N];
    for(int i=0;i<N;i++)
    {
        *(a+i)=i+1;
    }
    
    do{
        if(isValid(a,N,k))cnt++;
    }while(next_permutation(a,a+N));
    cout<<cnt;
    return 0;
}