#include <iostream>

// insertion, deletion and merging
class OrderedLinkedList
{
private:
    struct Node
    {
        char data;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;
    void addToHead(char data);
    void addToTail(char data);
    void removeFromHead();
    void removeFromTail();
    void insert(int index, char data);

public:
    OrderedLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void remove(int index);

    void display(const OrderedLinkedList &obj)
    {
        Node *p = obj.head;
        while(p)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
    }

    void insert(char element)       // ordered acc to their ascii value
    {
        Node *p = head;
        int i = 0;
        while (p != NULL)
        {
            if (element <= p->data)
            {
                insert(i, element);
                return;
            }
            p = p->next;
            i++;
        }
        insert(i, element);
    }

    void display()
    {
        if (head == NULL)
        {
            std::cout << "List is Empty\n";
            return;
        }
        Node *p = head;
        std::cout << "Size: " << size << "\n";
        while (p->next != NULL)
        {
            std::cout << p->data << " -> ";
            p = p->next;
        }
        std::cout << p->data;
        std::cout << "\n";
    }

    Node *begin() const
    {
        return head;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    int search(char key)
    {
        Node *p = head;
        int i = 0;
        while (p != NULL)
        {
            if (p->data == key)
                return i;
            p = p->next;
            i++;
        }
        return -1;
    }

    ~OrderedLinkedList()
    {
        Node *p = head;
        Node *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        head = tail = NULL;
    }
};

void OrderedLinkedList::addToHead(char data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    size++;
}

void OrderedLinkedList::addToTail(char data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;
    if (head == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    size++;
}

void OrderedLinkedList::removeFromHead()
{
    if (head == NULL)
    {
        std::cout << "List is Empty\n";
        return;
    }
    Node *p = head;
    if (head == tail) // this means there is only 1 element
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
    }
    delete p;
    size--;
}

void OrderedLinkedList::removeFromTail()
{
    if (head == NULL)
    {
        std::cout << "List is Empty\n";
        return;
    }
    Node *p = head;
    if (head == tail) // means there is only 1 element
    {
        head = tail = NULL;
    }
    else
    {
        while (p->next != tail)
        {
            p = p->next;
        }
        Node *q = p;
        p = p->next;
        q->next = NULL;
        tail = q;
    }
    delete p;
    size--;
}

void OrderedLinkedList::insert(int index, char data) // zero based indexing
{
    if ((index > size) || (index < 0))
    {
        std::cout << "Invalid Index\n";
        return;
    }
    if (index == size)
    {
        addToTail(data);
        return;
    }
    if (index == 0)
    {
        addToHead(data);
        return;
    }
    Node *p = head;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    Node *r = new Node;
    r->data = data;
    r->next = q;
    p->next = r;
    size++;
}

void OrderedLinkedList::remove(int index)
{
    if ((index > size - 1) || (index < 0))
    {
        std::cout << "Invalid Index\n";
        return;
    }
    if (index == size - 1)
    {
        removeFromTail();
        return;
    }
    if (index == 0)
    {
        removeFromHead();
        return;
    }
    Node *p = head;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    Node *r = q->next;
    p->next = r;
    delete q;
    size--;
}

int main()
{
    OrderedLinkedList A;
    int option;

    while (option != 5)
    {
        std::cout << "MENU\n";
        std::cout << "Select option\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Display\n";
        std::cout << "4. Search\n";
        std::cout << "5. End\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
        {
            char ch;
            std::cout << "Enter a character value: ";
            std::cin >> ch;
            A.insert(ch);
        }
        break;

        case 2:
        {
            int pos;
            std::cout << "Enter position: ";
            std::cin >> pos;
            A.remove(pos - 1);
        }
        break;

        case 3:
            A.display();
            break;


        case 4:
        {
            char key;
            std::cout << "Enter value you want to search: ";
            std::cin >> key;
            int searchResult = A.search(key);
            if (searchResult == -1)
                std::cout << "Element not found\n";
            else
                std::cout << "Element found at postion " << searchResult + 1 << "\n";
            break;
        }

        case 5:
            break;
        default:
            std::cout << "Incorrect option\n";
        }
        std::cin.get();
        std::cout << "Press Enter to ";
        option == 5 ? std::cout << "exit..." : std::cout << "continue...";
        std::cin.get();
        std::cout << "\n";
    }
    return 0;
}