#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct linklist node;
struct linklist
{
    int addr=0;
    int data=0;
    int next=0;
    node *Next=nullptr;
};

int depth(node* h)
{
    node* p=h;
    int n;
    while(p)
    {
        n++;
        p=p->Next;
    }
    return n;
}

node* find(node* h,int addr,int N)
{
    while(N--)
    {
        if((h+N)->addr==addr)return (h+N);
    }
    return nullptr;
}

void swap(node *n)
{
    node *temp = n->Prev;
    n->Prev = n->Next;
    n->Next = temp;
}

void print(node* h)
{
    node* p =h;
    while(p)
    {
        if(p->next!=-1)
        printf("%05d %d %05d\n",p->addr,p->data,p->next);
        else
        printf("%05d %d %d\n",p->addr,p->data,p->next);
        p = p->Next;
    };
}

node* findK(node *head, int N)
{
    node* p=head;
    if(N<0)return nullptr;
    while((N--)&&p)p=p->Next;
    return p;
}

node* reverse(node* h,int N,int K)
{
    const int seg = N/K*K;
    node *before,*first,*last,*after,*prev2,*prev,*curr=h;
    int i=0;
    while(i<=seg)
    {
        if(i%K==0)
        {
            before = curr;

        }
        else if(i%K==1)
        {
            first = curr;
        }
        else if(i%K==K-1)
        {
            
        }
        else
        {
            p->Next =prev;
        }
        
    }
    return p;
}

int main()
{
    int addr0,addr,N,K,data,next;
    scanf("%d %d %d",&addr0,&N,&K);
    node* head = (node*)malloc(sizeof(node)*N);
    node const *dumy = (node *)malloc(sizeof(node));
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d",&addr,&data,&next);
        (head+i)->addr = addr;
        (head+i)->data = data;
        (head+i)->next = next;
        (head+i)->Next = nullptr;
    }
    node* h = find(head,addr0,N);
    node* p =h;
    while(p!=nullptr)
    {
        p->Next = find(head,p->next,N);
        if(p->Next==nullptr)break;
        p = p->Next;
    }

    N = depth(h);
    dumy->Next = h;
    h = reverse(h,N,K);
    p=h;
    while(p->Next)
    {
        p->next = p->Next->addr;
        p=p->Next;
    }
    p->next = -1;
    print(h);

    return 0;
}