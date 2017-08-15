#include<iostream>
using namespace std;

int main()
{
    string A,Q="";
    int a,B,R,q;
    cin>>A>>B;
    char *p= (char *)A.c_str();
    while(*p)
    {
        a=R*10+(*p-'0');
        q=a/B;
        Q+=string(1,(char)(q+'0'));
        R=a-q*B;
        p++;
    }
    p=(char *)Q.c_str();
    if(*p=='0'&&*(p+1)!='\0')
    p++;
    cout<<string(p)<<" "<<R<<endl;
    return 0;
}