// 今日头条后台实习2017
// 给定 x, k ，求满足 x + y = x | y 的第 k 小的正整数 y 。 | 是二进制的或(or)运算，例如 3 | 5 = 7。
// 比如当 x=5，k=1时返回 2，因为5+1=6 不等于 5|1=5，而 5+2=7 等于 5 | 2 = 7。

// 输入描述:
// 每组测试用例仅包含一组数据，每组数据为两个正整数 x , k。 满足 0 < x , k ≤ 2,000,000,000。


// 输出描述:
// 输出一个数y。

// 输入例子1:
// 5 1

// 输出例子1:
// 2
#include<iostream>
using namespace std;

int main()
{
    unsigned int x,k,cnt=0;
    cin>>x>>k;
    for(unsigned int i=1;;i++)
    {
        if(x+i==(unsigned int)(x|i))
        {
            cnt++;
        }
        if(cnt==k)
        {
            cout<<i;
            return 0;
        }

    }
}
