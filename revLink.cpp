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
    node *Prev=nullptr;
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

node* reverse(node* before,node *last)
{
    node *after = last->Next;
    node *p = last;
    while(p->Prev!=before)
    {
        p=p->Prev;
        swap(p->Next);
    }
    p->Prev = p->Next;
    p->Next = after;
    last->Prev = before;
    while(p->Prev!=nullptr)
    {
        p=p->Prev;
    }
    return p;
}

int main()
{
    int addr0,addr,N,K,data,next;
    scanf("%d %d %d",&addr0,&N,&K);
    node* head = (node*)malloc(sizeof(node)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d",&addr,&data,&next);
        (head+i)->addr = addr;
        (head+i)->data = data;
        (head+i)->next = next;
        (head+i)->Prev = nullptr;
        (head+i)->Next = nullptr;
    }
    node* h = find(head,addr0,N);
    node* p =h;
    while(p!=nullptr)
    {
        p->Next = find(head,p->next,N);
        if(p->Next==nullptr)break;
        p->Next->Prev = p;
        p = p->Next;
    }

    N = depth(h);
    for(int i=0;i<N/K;i++)
    {
        h = reverse(findK(h,i*K-1),findK(h,(i+1)*K-1));
    }
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