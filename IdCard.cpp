#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class IdCard
{
public:
    IdCard(string Id)
    {
        this->Id = Id;
    };
    ~IdCard(){};
    string Id;
    bool isValid()
    {
        char *p = (char *)((this->Id).c_str());
        char w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char M[11]={'1','0','x','9','8','7','6','5','4','3','2'};
        int sum=0;
        for(int i=0;i<17;i++)
        {
            if(*(p+i)-'0'>=0&&*(p+i)-'0'<=9)
            sum+=(*(p+i)-'0')*w[i];
            else
            return false;
        }
        sum = sum%11;
        if(*(p+17)==M[sum])return true;
        else return false;
    }

};

int main()
{
    int N;
    cin>>N;
    string s;
    vector<IdCard> vectorCard;
    while(N--)
    {
        cin>>s;
        IdCard i = IdCard(s);
        if(!i.isValid())vectorCard.push_back(i);
    }
    if(vectorCard.size()==0)
    {
        cout<<"All passed";
    }
    else
    {
        for(vector<IdCard>::iterator t=vectorCard.begin();t<vectorCard.end();t++)
        {
            cout<<t->Id<<endl;
        }
    }
    return 0;
}