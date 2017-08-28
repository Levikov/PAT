//Netease 2018 #4
#include<iostream>
using namespace std;
void reverse(int *a,int n)
{
    for(int i=0;i<n/2;i++)
    {
        int temp =*(a+i);
        *(a+i)=*(a+N-1-i);
        *(a+N-1-i) = temp;
    }
}


int *getArray(int *a,int N)
{
    reverse(a+1,N-1);
}

int main()
{
    int N;
    cin
}