#include <iostream>
#include <deque>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

void makeTree(int *pre, int *mid, node *n, int N)
{
    int Nl = 0, Nr = 0;
    n->data = pre[0];
    while (mid[Nl++] != pre[0])
        ;
    Nl--;
    Nr = N - Nl - 1;
    if (Nl > 0)
    {
        n->left = new node();
        makeTree(pre + 1, mid, n->left, Nl);
    }
    else
    {
        n->left = NULL;
    }

    if (Nr > 0)
    {
        n->right = new node();
        makeTree(pre + Nl + 1, mid + 1 + Nl, n->right, Nr);
    }
    else
        n->right = NULL;
}

void flipTree(node *n)
{
    if (n != nullptr)
    {
        node *temp = n->left;
        n->left = n->right;
        n->right = temp;
        flipTree(n->left);
        flipTree(n->right);
    }
    else
        return;
}
void level_traverse(node *n)
{
    bool flag = false;
    deque<node *> que;
    que.push_back(n);
    while (!que.empty())
    {
        if (que[0]->left != NULL)
            que.push_back(que[0]->left);
        if (que[0]->right != NULL)
            que.push_back(que[0]->right);
        if (!flag)
        {
            cout << que[0]->data;
            flag = true;
        }
        else
            cout << " " << que[0]->data;
        que.pop_front();
    }
}

int main()
{
    int N, *pre, *mid;
    node *Node = new node();
    cin >> N;
    pre = new int[N];
    mid = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> mid[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> pre[i];
    }
    makeTree(pre, mid, Node, N);
    flipTree(Node);
    level_traverse(Node);
}