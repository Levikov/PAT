#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
struct node{
    char color;
    int x;
    int y;
    int z;
};
class tri 
{
public:
    node nodes[3];
    tri(node n1,node n2,node n3)
    {
        nodes[0] = n1;
        nodes[1] = n2;
        nodes[2] = n3;
    }
    bool isValid()
    {
        return (nodes[0].color==nodes[1].color&&nodes[1].color==nodes[2].color||nodes[0].color!=nodes[1].color&&nodes[1].color!=nodes[2].color&&nodes[2].color!=nodes[0].color);
    }
    double calcS()
    {
        int *s = new int[3];
        int temp =0;
        for(int i=0;i<3;i++)
        s[i] = sqrt(
                    (nodes[i].x-nodes[(i+1)%3].x)*(nodes[i].x-nodes[(i+1)%3].x) +
                    (nodes[i].y-nodes[(i+1)%3].y)*(nodes[i].y-nodes[(i+1)%3].y) +
                    (nodes[i].z-nodes[(i+1)%3].z)*(nodes[i].z-nodes[(i+1)%3].z));
        temp = (s[0]+s[1]+s[2])/2;
        return (sqrt(temp*(temp-s[0])*(temp-s[1])*(temp-s[2])));
    }
};
int main()
{
    int N;double max=0;
    cin>>N;
    node* n = new node[N];
    for(int i=0;i<N;i++)
    {
        cin>>(n+i)->color>>(n+i)->x>>(n+i)->y>>(n+i)->z;
    }
    for(int i=0;i<N-2;i++)
    for(int j=i+1;j<N-1;j++)
    for(int k=j+1;k<N;k++)
    {
        tri t = tri(*(n+i),*(n+j),*(n+k));
        if(t.isValid())
        {
            double ss=t.calcS();
            if(ss>max)max =ss;
        }
    }

    delete []n;
    printf("%.5f",max);
    
    
}