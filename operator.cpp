#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

class number
{
public:
    int a;
    int b;
    number(){};
    number(int a,int b)
    {
        this->a = a;
        this->b = b;
    };
    void simplify()
    {

    };
    void print(){};
    number operator +(number A)
    {
        return A;
    };
    ~number(){};

};
int main()
{
    int a,b,c,d;
    scanf("%d/%d %d/%d",&a,&b,&c,&d);
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}