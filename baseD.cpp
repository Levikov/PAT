#include<iostream>
using namespace std;
int main()
{
    long A,B,C,D;
    string o ="";
    cin>>A>>B>>D;
    C = A + B;
    A = 1;
    while(A*D<=C)A*=D;

    while(A)
    {
        o+= string(1,C/A+'0');
        C-=C/A*A;
        A=A/D;
    }
    cout<<o;
    return 0;
}