#include<iostream>
using namespace std;
class sandglass
{
public:
    int total;
    int level;
    int rest;
    char symbol;
    sandglass(int n,char c)
    {
        this->symbol = c;
        this->total = n;
        this->rest = n;
        this->level=0;
        while(usage(this->level)<=this->rest)
        {
            this->rest-=usage(this->level);
            this->level++;
        }
        this->level--;
    };
    ~sandglass(){};
    void print(int n)
    {
        int s=this->level-n,c=2*n-1;
        while(s--)cout<<" ";
        while(c--)cout<<symbol;
        cout<<endl;
    }
    void printAll()
    {
        int N = this->level;
        while(N--)print(N+1);N++;N++;
        while(N++<this->level)print(N);
    }
    int usage(int l)
    {
        if(l==0)return 0;
        else if(l==1)return 1;
        else return 4*l-2;
    }
};
int main()
{
    int N;
    char c;
    cin>>N>>c;
    sandglass obj = sandglass(N,c);
    obj.printAll();
    cout<<obj.rest;
    return 0;
}