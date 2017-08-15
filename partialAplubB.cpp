#include<iostream>
using namespace std;

int main()
{
  int Da,Db,Pa=0,Pb=0;
  string A,B;
  cin>>A>>Da>>B>>Db;
  char *p = (char *)A.c_str();
  while(*p)
  {
      if(*p-'0'==Da)Pa=Pa*10+Da;
      p++;
  }
  p = (char *)B.c_str();
  while(*p)
  {
      if(*p-'0'==Db)Pb=Pb*10+Db;
      p++;
  }
  cout<<Pa+Pb<<endl;
  return 0;
}