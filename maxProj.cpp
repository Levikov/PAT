#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct digit
{
    char c;
    unsigned long long n;
};

inline bool cmp(digit *a, digit *b)
{
    return (a->n) > (b->n);
}

int main()
{
    int N;
    cin >> N;
    string s;
    digit **p = new digit *[10];
    bool flag[10] = {false, false, false, false, false, false, false, false, false, false};
    for (int i = 0; i < 10; i++)
    {
        p[i] = new digit();
        p[i]->c = 'A' + i;
        p[i]->n = 0;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        flag[s.at(0) - 'A'] = true;
        unsigned long long arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        unsigned long long temp = 1;
        for (int j = s.length() - 1; j >= 0; j--)
        {
            arr[s.at(j) - 'A'] += temp;
            temp = temp * 10;
        }
        for (int j = 0; j < 10; j++)
        {
            p[j]->n += arr[j];
        }
    }
    sort(p, p + 10, cmp);

    if (flag[p[9]->c - 'A'])
        for (int i = 8; i >= 0; i--)
        {
            if (!flag[p[i]->c - 'A'])
            {
                digit *temp = *(p + 9);
                *(p + 9) = *(p + i);
                *(p + i) = temp;
                break;
            }
        }
    sort(p, p + 9, cmp);
    unsigned long long sum = 0;
    for (int i = 0, temp = 9; i < 10; i++, temp--)
    {
        sum += temp * p[i]->n;
    }
    cout << sum;
    return 0;
}
