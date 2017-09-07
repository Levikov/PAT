//今日头条后端实习生2017
// 有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？
// 输入描述:
// 每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，且至少存在一个字符不是任何字符串的首字母。
// 输出描述:
// 输出一个数，表示最大和是多少。
// 输入例子1:

// 2
// ABC
// BCA

// 输出例子1:
// 1875
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
