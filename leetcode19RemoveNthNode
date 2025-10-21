// Remove the Nth node from the end
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class list
{
public:
    Node *head;
    Node *tail;
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void Printlist()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL";
    }
    Node *removeNthfromend(Node *head, int n)
    {
        int count = 0;
        Node *temp1 = head;
        Node *temp2 = head;
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
            count++;
        }
        if (count == 1 && n == 1)
        {
            return NULL;
        }
        if (count == n)
        {
            return head->next;
        }
        for (int i = 1; i < count - n; i++)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};
int main()
{
    list ll;
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    Node *result = ll.removeNthfromend(ll.head, 3);
    ll.Printlist();
    return 0;
}
