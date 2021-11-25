#include <iostream>
using namespace std;

class Queue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    void enqueue(int data)
    {
        Node *p = new Node(data);
        if (front == NULL)
        {
            front = rear = p;
        }
        else
        {
            p->prev = rear;
            rear->next = p;
            rear = p;
        }
        size++;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty\n";
            return;
        }
        Node *p = front;
        if (front == rear) // this means there is only 1 element
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }
        delete p;
        size--;
    }

    void display()
    {
        if (front == NULL)
        {
            std::cout << "Queue is Empty\n";
            return;
        }
        Node *p = front;
        std::cout << "Size: " << size << "\n";
        while (p != NULL)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << "\n";
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    }

    ~Queue()
    {
        Node *p = front;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }
};

int main()
{
    Queue q;
    int option;
    while (option != 5)
    {
        cout << "MENU\n";
        cout << "Select option\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty?\n";
        cout << "4. Display\n";
        cout << "5. End\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
            int x;
            cout << "Enter an integer value: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Queue is ";
            if (q.isEmpty())
            {
                cout << "empty\n";
            }
            else
            {
                cout << "not empty\n";
            }
            break;

        case 4:
            q.display();

        case 5:
            break;
        default:
            cout << "Incorrect option\n";
        }
        cin.get();
        cout << "Press Enter to ";
        option == 5 ? cout << "exit..." : cout << "continue...";
        cin.get();
        cout << "\n";
    }
    return 0;
}
