#include<iostream>
using namespace std;
inline string padleft(string s)
{
    while(s.length()<10)
    {
        s = "0"+s;
    }
    return s;
}
int main()
{
    int N,cnt=0;
    string min="9999/99/99",max="0000/00/00",minname,maxname,name,birth;
    cin>>N;
    while(N--)
    {
        cin>>name>>birth;
        birth = padleft(birth);
        if(birth<"1814/09/06"||birth>"2014/09/06")
        continue;
        else
        {
            cnt++;
            if(birth<min)
            {
                min = birth;
                minname = name;
            }
            if(birth>max)
            {
                max=birth;
                maxname=name;
            }
        }
    }
    cout<<cnt<<" "<<minname<<" "<<maxname;
    return 0;
}