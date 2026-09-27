#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node* head;

    CircularLinkedList()
    {
        head = NULL;
    }


    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }


    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    
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
        temp->next = newNode;
    }

   
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

    
        if (head->data == value && head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        
        if (head->data == value)
        {
            Node* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            Node* temp = head;

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

     
        Node* temp = head;

        while (temp->next != head)
        {
            if (temp->next->data == value)
            {
                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;

                delete deleteNode;
                return;
            }

            temp = temp->next;
        }

        cout << "Node not found!" << endl;
    }

    
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
            cout << temp->data << "->";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main()
{
    CircularLinkedList list;

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
