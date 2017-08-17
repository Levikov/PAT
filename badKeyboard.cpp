#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline char conv2Cap(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a' + 'A');
    else
        return c;
}

class keyboard
{
  public:
    string norm;
    string bad;
    vector<char> vBad;
    keyboard(string n, string b)
    {
        norm = n;
        bad = b;
    };
    ~keyboard(){

    };
    void getBad()
    {
        char *p = (char *)norm.c_str();
        char *q = (char *)bad.c_str();
        while (*p)
        {
            if (isBad(*p))
            {
                p++;
            }
            else
            {
                if (*p != *q)
                {
                    vBad.push_back(conv2Cap(*p));
                    p++;
                }
                else
                {
                    p++;
                    q++;
                }
            }
        }
    }
    bool isBad(char c)
    {
        return !(find(vBad.begin(), vBad.end(), conv2Cap(c)) == vBad.end());
    }
    void print()
    {
        for (int i = 0; i < vBad.size(); i++)
        {
            cout << vBad[i];
        }
    }
};

int main()
{
    string norm, bad;
    cin >> norm;
    cin >> bad;
    keyboard k(norm, bad);
    k.getBad();
    k.print();
    return 0;
}