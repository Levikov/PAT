#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
class cake
{
public:
    int amount;
    int value;
    float price;
    cake(int amount)
    {
        this->amount = amount;
    };
    ~cake(){};
    void getValue(int value)
    {
        this->value = value;
        this->price = (float)value/amount;
    };
};

bool cmp(cake A,cake B)
{
    return (A.price>B.price);
}

int main()
{
    int N,A;
    float V=0;
    cin>>N>>A;
    vector<cake> v;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        v.push_back(cake(a));
    }
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        v[i].getValue(a);
    }
    sort(v.begin(),v.end(),cmp);
    for(vector<cake>::iterator c=v.begin();c<v.end();c++)
    {
        if(A>=c->amount)
        {
            A-=c->amount;
            V +=c->value;
        }else
        {
            V+=c->price*A;
            break;
        }
    }
    printf("%.2f",V);
    

    
}