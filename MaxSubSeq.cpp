#include<iostream>
using namespace std;

inline int max(int a,int b)
{
  return a>b?a:b;
}

int sum(int *a,int **first,int **last,int N)
{
    int sum=0,max=0,*p=a,*q;
    for(int i=0;i<N;i++)
    {
        if(a[i]>=0)
        {
            sum+=a[i];
            if(sum>=max)
            {
                q =a+i;
                max = sum; 
            }
        }else
        {
            sum=0;
        }

        if(i>0&&a[i]>=0&&a[i-1]<0)p=a+i;
    }
    *first =p;
    *last =q;
    return max;
}

int main()
{
  int N;
  cin>>N;
  int a[N],*p,*q;
  for(int i=0;i<N;i++)
  {
    cin>>a[i];
    
  }
  int r=sum(a,&p,&q,N);
  cout<<r<<" "<<*p<<" "<<*q;
  return 0;
}