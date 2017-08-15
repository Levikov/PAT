#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string c,s,o="";
    vector<char> v;
    cin>>c;
    cin>>s;
    char *p = (char *)c.c_str();
    while(*p)
    {
        if(*p>='A'&&*p<='Z')
        {
            v.push_back(*p);
            v.push_back(*p-'A'+'a');
        }
        else if(*p=='+')
        {
            for(int i=0;i<26;i++)
            {
                v.push_back('A'+i);
            }
        }
        else
        {
            v.push_back(*p);
        }
        p++;
    }
    p = (char *)s.c_str();
    while(*p)
    {
        if(find(v.begin(),v.end(),*p)==v.end())
        o+=string(1,*p);
        p++;
    }
    cout<<o;
    return 0;
}