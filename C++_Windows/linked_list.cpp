#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void print_list(Node *head)
{
    Node* cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void insert_head(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insert_tail(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void delete_node(Node *&head, int target)
{
    if (head == nullptr)
        return;

    if (head->data == target)
    {
        Node *todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    Node *prev = head;
    Node *cur = head->next;
    while (cur != nullptr)
    {
        if (cur->data == target)
        {
            prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void delete_list(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;

    insert_head(head, 10);
    insert_tail(head, 30);
    insert_head(head, 20);

    print_list(head);

    insert_tail(head, 100);

    print_list(head);
    
    delete_node(head, 100);

    print_list(head);

    delete_list(head);

    return 0;
}