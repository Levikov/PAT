#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class student
{
public:
    int Id;
    int Dmark;
    int Cmark;
    student(int Id,int Dmark,int Cmark)
    {
        this->Id = Id;
        this->Dmark=Dmark;
        this->Cmark=Cmark;
    };
    ~student(){};
    void disp()
    {
        cout<<this->Id<<" "<<this->Dmark<<" "<<this->Cmark<<endl;
    }
};
bool cmp(student A,student B)
{
    if(A.Dmark+A.Cmark>B.Dmark+B.Cmark)
    {
        return true;
    }else if(A.Dmark+A.Cmark==B.Dmark+B.Cmark)
    {
        if(A.Dmark>B.Dmark)return true;
        else if(A.Dmark==B.Dmark)
        {
            if(A.Id<B.Id)return true;
            else return false;
        }
        else
        return false;
    }
    else
    return false;
}
int main()
{
    int N,L,H,Id,Dmark,Cmark;
    cin>>N>>L>>H;
    vector<student> vDC;
    vector<student> vD;
    vector<student> vC;
    vector<student> v;
    while(N--)
    {
        cin>>Id>>Dmark>>Cmark;
        if(Dmark>=H&&Cmark>=H)
        {
            vDC.push_back(student(Id,Dmark,Cmark));
            continue;
        }else if(Dmark>=H&&Cmark>=L)
        {
            vD.push_back(student(Id,Dmark,Cmark));
            continue;
        }
        else if(Dmark>=L&&Cmark>=L&&Dmark>=Cmark)
        {
            vC.push_back(student(Id,Dmark,Cmark));
            continue;
        }
        else if(Dmark>=L&&Cmark>=L)
        {
            v.push_back(student(Id,Dmark,Cmark));
            continue;
        }   
    }
    cout<<vDC.size()+vD.size()+vC.size()+v.size()<<endl;
    sort(vDC.begin(),vDC.end(),cmp);
    for(vector<student>::iterator it=vDC.begin();it!=vDC.end();it++)
    {
        it->disp();
    }
    sort(vD.begin(),vD.end(),cmp);
    for(vector<student>::iterator it=vD.begin();it!=vD.end();it++)
    {
        it->disp();
    }
    sort(vC.begin(),vC.end(),cmp);
    for(vector<student>::iterator it=vC.begin();it!=vC.end();it++)
    {
        it->disp();
    }
    sort(v.begin(),v.end(),cmp);
    for(vector<student>::iterator it=v.begin();it!=v.end();it++)
    {
        it->disp();
    }
    return 0;
}