#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
///////////////////////delete duplicate nodes/////////////

void deleteDuplicate(node *&head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            node *todelete = temp->next;

            temp->next = temp->next->next;

            delete todelete;
        }
        temp = temp->next;
    }
}

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}
void insertAttail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
int main()
{
    node *newhead = NULL;
    int arr[6] = {11, 11, 3, 43, 43, 60};
    for (int i = 0; i < 6; i++)
    {
        insertAttail(newhead, arr[i]);
    }
    display(newhead);
    deleteDuplicate(newhead);
    display(newhead);
    return 0;
}