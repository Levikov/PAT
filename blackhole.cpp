#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
class black
{
public:
    int N;
    int A;
    int B;
    int C;
    black(short n)
    {
        this->N = n;
        char *a = (char *)malloc(5);*(a+4)='\0';
        char *b = (char *)malloc(5);*(b+4)='\0';
        char *p =a;
        sprintf(a,"%04d",n);
        vector<char> v;
        while(*p)
        {
            v.push_back(*p);
            p++;
        }
        sort(v.begin(),v.end(),this->descend);
        for(int i=0;i<4;i++)
        {
            *(a+i)=v[i];
        }
        sort(v.begin(),v.end(),this->ascend);
        for(int i=0;i<4;i++)
        {
            *(b+i)=v[i];
        }
        sscanf(a,"%04d",&(this->A));
        sscanf(b,"%04d",&(this->B));        
        this->C = this->A - this->B;
        free(a);free(b);
    };
    ~black(){};
    bool isHole()
    {
        return (C==6174||C==0);
    };
    void print()
    {
        printf("%04d - %04d = %04d\n",A,B,C);
    }
    static bool ascend(char a,char b)
    {
        return (a<=b);
    };
    static bool descend(char a,char b)
    {
        return (a>=b);
    };

};

int main()
{
    int N;
    cin>>N;
    black A = black(N);
    do
    {
        A = black(N);
        A.print();
        N = A.C;
    }while(!A.isHole());
    return 0;
}