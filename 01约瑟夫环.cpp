#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} Node;

void Josephus(int N,int M);

int main() // 链表实现
{
    int N,M;
    cout<<"请输入总人数N,和报到M号的人出具的M\n";
    cin>>N>>M;
    Josephus(N,M);
    return 0;
}

void Josephus(int N, int M)
{
    Node *head = NULL, *p = NULL, *r = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    p=head;
    for (int i = 2; i <= N; i++)
    {
        r = (Node *)malloc(sizeof(Node));
        r->data=i;
        r->next=NULL;
        p->next=r;
        p=r;
    }
    p->next=head;
    p=head;
    while(p->next!=p)
    {
        for(int i=1;i<M;i++)
        {
            r=p;
            p=p->next;
        }
        printf("%d ",p->data);
        r->next=p->next;
        p=p->next;
    }
    cout<<p->data;
}