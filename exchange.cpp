#include<iostream>
#include<stdio.h>
using namespace std;

class money
{
public:
    int G;
    int S;
    int K;
    money(int a,int b,int c){G=a;S=b;K=c;};
    ~money(){};
    money operator+(money m)
    {
        money a(G+m.G,S+m.S,K+m.K);
        a.organize();
        return a;
    };
    money operator-(money m)
    {
        m.G = -m.G;
        m.S = -m.S;
        m.K = -m.K;
        return (*this+m);
    };
    bool operator>=(money m)
    {
        if(G<m.G)return false;
        else if(G>m.G)return true;
        else
        {
            if(S<m.S)return false;
            else if(S>m.S)return true;
            else
            {
                if(K<m.K)return false;
                else if(K>m.K)return true;
                else return true;
            }

        }
        
    }
    void organize()
    {
        if(K<0)
        {
            K=29+K;
            S--;
        }
        else if(K>=29)
        {
            K=K-29;
            S++;
        }else;
        if(S<0)
        {
            S=17+S;
            G--;
        }
        else if(S>=17)
        {
            S=S-17;
            G++;
        }else;

    }
    void print()
    {
        cout<<G<<"."<<S<<"."<<K<<endl;
    };

};

int main()
{
    int G1,S1,K1,G2,S2,K2;
    scanf("%d.%d.%d %d.%d.%d",&G1,&S1,&K1,&G2,&S2,&K2);
    money m1(G1,S1,K1);
    money m2(G2,S2,K2);
    if(m2>=m1)(m2-m1).print();
    else
    {
        m2 = m1-m2;
        m2.G = -m2.G;
        m2.print();
    }
    return 0;
}