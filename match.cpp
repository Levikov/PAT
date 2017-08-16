#include<iostream>
using namespace std;
class player
{
public:
    int cnt[3];
    int result[3];
    player()
    {
        this->cnt[0]=0;
        this->cnt[1]=0;
        this->cnt[2]=0;
        this->result[0]=0;
        this->result[1]=0;
        this->result[2]=0;
    };
    ~player(){};
    void record(char r,char c)
    {
        this->result[r]++;
        if(r==0)
        switch(c)
        {
            case 'B':this->cnt[0]++;break;
            case 'C':this->cnt[1]++;break;
            case 'J':this->cnt[2]++;break;
            default:break;
        };
    };
    void printResult()
    {
        cout<<this->result[0]<<" "<<this->result[1]<<" "<<this->result[2]<<endl;
    };
    char getMaxWin()
    {
        if(isMax(0))return 'B';
        if(isMax(1))return 'C';
        if(isMax(2))return 'J';
        return 0;
    };
private:
    bool isMax(char c)
    {
        for(int i=0;i<3;i++)
        if(cnt[i]>cnt[c])return false;
        return true;
    };

};

inline char judge(char a,char b)
{
    if(a==b)return 1;
    else if(a<b)
    {
        if(a=='B'&&b=='J')return 2;
        else return 0;
    }
    else
    {
        if(a=='J'&&b=='B')return 0;
        else return 2;
    }
}

int main()
{
    int N;
    char a,b;
    player A,B;
    cin>>N;
    while(N--)
    {
        cin>>a>>b;
        A.record(judge(a,b),a);
        B.record(judge(b,a),b);
    }
    A.printResult();
    B.printResult();
    cout<<A.getMaxWin()<<" "<<B.getMaxWin();
    return 0;
}