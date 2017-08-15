#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class school
{
public:
    int id;
    int score;
    school()
    {
        this->id=0;
        this->score=0;
    };
    school(int id)
    {
        this->id=id;
        this->score=0;
    };
    ~school(){};
    void add(int score)
    {
        this->score+=score;
    };
};

int main()
{
    int N,id,score;
    school max=school();
    cin>>N;
    vector<school> v;
    while(N--)
    {
        cin>>id>>score;
        if(v.size()<id)
        {
            for(int i=v.size();i<id;i++)v.push_back(school(i+1));
        }
        v[id-1].add(score);
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i].score>max.score)max=v[i];
    }
    cout<<max.id<<" "<<max.score<<endl;

    return 0;
}