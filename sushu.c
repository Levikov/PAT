#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

inline bool isNum(int num)
{
    if(num==2)return true;
    for(int i=2;i<sqrt(num)+1;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

int getNum(int *num,const int M,const int N)
{
    int cnt=0,i=2,cnt2=0;
    int *p= num;
    while(cnt<N)
    {
        if(isNum(i))
        {
            cnt++;
            if(cnt<=N&&cnt>=M)
            {
                *p = i;
                p++;
                cnt2++;
            }
        }
        i++;

    }
    return cnt2;
}

void print(int *num,int N)
{
    for(int i=0;i<N;i++)
    {
        if(i!=N-1)
        (i%10==9)?(printf("%d\n",num[i])):(printf("%d ",num[i]));
        else
        printf("%d",num[i]);

    }
}
int main()
{
    int M,N,P;
    int *num = (int *)malloc(sizeof(int)*(N-M+1));
    scanf("%d %d",&M,&N);
    P = getNum(num,M,N);
    print(num,P);
    return 0;
}