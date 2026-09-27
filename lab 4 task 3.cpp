#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyLinkedList
{
public:
    Node* head;

    CircularDoublyLinkedList()
    {
        head = NULL;
    }

    // ii. Insert at end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    // iii. Insert at beginning
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // iv. Insert at given position
    void insertAtPosition(int value, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        if (head == NULL)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid position!" << endl;
                return;
            }
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // v. Delete any node by value
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        // Search for node
        do
        {
            if (temp->data == value)
            {
                break;
            }

            temp = temp->next;
        }
        while (temp != head);

        // Node not found
        if (temp->data != value)
        {
            cout << "Node not found!" << endl;
            return;
        }

        // Only one node
        if (temp->next == temp)
        {
            delete temp;
            head = NULL;
            return;
        }

        // If deleting head
        if (temp == head)
        {
            Node* last = head->prev;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete temp;
            return;
        }

        // Delete any other node
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    // vi. Print complete circular doubly linked list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main()
{
    CircularDoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Original List: ";
    list.display();

    list.insertAtBeginning(5);

    cout << "After inserting 5 at beginning: ";
    list.display();

    list.insertAtEnd(40);

    cout << "After inserting 40 at end: ";
    list.display();

    list.insertAtPosition(25, 4);

    cout << "After inserting 25 at position 4: ";
    list.display();

    list.deleteNode(20);

    cout << "After deleting 20: ";
    list.display();

    return 0;
}
