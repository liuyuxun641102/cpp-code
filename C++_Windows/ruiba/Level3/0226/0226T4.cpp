#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};

Node *p, *head, *tail;

void insert(Node *head, int x, int i)
{
    Node *p, *s; int j;
    p = head;
    j = 0;
    while ((p != NULL) && (j < i - 1))
    {
        p = p -> next;
        j++;
    }
    if (p == NULL)
    {
        cout << "没有位置插入";
    }
    else
    {
        s = new Node;
        s -> data = x;
        s -> next = p -> next;
        p -> next = s;
    }
}

int main()
{
    int x;
    cin >> x;
    head = new Node;
    tail = head;
    while (x != -1)
    {
        p = new Node;
        p -> data = x;
        p -> next = NULL;
        tail -> next = p;
        tail = p;
        cin >> x;
    }

    p = head -> next;
    while ((p -> data != x) && (p -> next != NULL))
    {
        p = p -> next;
    }

    if (p -> data == 9)
    {
        cout << "找到9";
    }
    else
    {
        cout << "不存在";
    }
    insert (head, 999, 3);
    p = head -> next;
    while (p -> next != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << p -> data << endl;
    return 0;
}