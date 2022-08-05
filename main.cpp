#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// class LinkedList
// {
//     Node *head;
//     Node *tail;

// public:
//     LinkedList() {}
//     LinkedList(int d)
//     {
//         Node n(d);
//}
// };

void build() {}
// insert
void insertATHead(Node *&head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }

    Node *n;
    n = new Node(d);
    n->next = head;
    head = n;
}

int length(Node *head)
{
    int c = 0;

    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}
// if you are not maintaing the tail pointer
// void insertAtTail(Node *head, int data)
// {
//     if (head == NULL)
//     {
//         head = new Node(data);
//         return;
//     }
//     Node *tail = head;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }
//     Node *x = new Node(data);
//     tail->next = x;
//     x = tail;
// }
void insertAtTail(Node *tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
    }
    Node *x = new Node(data);
    tail->next = x;
    x = tail;
}
void insertAtMiddle(Node *&head, Node *&tail, int d, int p)
{
    if (head == NULL or p == 0)
    {
        insertATHead(head, d);
    }
    else if (p > length(head))
    {
        insertAtTail(tail, d);
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i <= p - 1; i++)
        {
            temp = temp->next;
        }
        Node *n = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

// delete
void deleteHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "NULL"
             << "\n";
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
}

void deleteTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "NULL"
             << "\n";
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deletePosition(Node *head, int p)
{
    if (p == 0)
    {
        deleteHead(head);
    }
    Node *temp;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << "\n";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertATHead(head, 4);
    tail = head;
    insertATHead(head, 3);
    insertATHead(head, 1);
    insertATHead(head, 0);
    insertAtMiddle(head, tail, 22, 10);
    print(head);
    deleteHead(head);
    print(head);
    deleteTail(head);
    print(head);
}
