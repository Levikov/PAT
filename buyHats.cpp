#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int N, p;
    vector<int> v;
    cin >> N;
    while (N--)
    {
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for(int i=0,min=v[0],count=1;i<v.size();i++)
    {
        if(v[i]!=min)
        {
            min = v[i];
            count++;
            if(count==3)
            {
                cout<<min;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}