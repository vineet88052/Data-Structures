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

    void merge(OrderedLinkedList &obj)
    {
        Node *p1 = head;
        Node *p2 = obj.head;
        Node *q;
        if (p1 == NULL && p2 == NULL)
        {
            return;
        }
        else if (p1 == NULL)
        {
            head = obj.head;
            tail = obj.tail;
            obj.head = obj.tail = NULL;
            this->size = obj.size;
            return;
        }
        else if (p2 == NULL)
        {
            return;
        }
        else if (p2->data < p1->data)
        {
            head = p2;
            q = p2;
            p2 = p2->next;
        }
        else
        {
            q = p1;
            p1 = p1->next;
        }

        if (obj.tail->data > tail->data)
        {
            tail = obj.tail;
        }

        while (p1!=NULL && p2!=NULL)
        {
            if (p1->data <= p2->data)
            {
                q->next = p1;
                p1 = p1->next;
                q = q->next;
            }
            else 
            {
                q->next = p2;
                p2 = p2->next;
                q = q->next;
            }
        }

        if(p1 == NULL)
            q->next = p2;
        else 
            q->next = p1;
        obj.head = obj.tail = NULL;
        this->size += obj.size;
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
    int n;
    char x;
    OrderedLinkedList A;
    std::cout << "Enter size of A: ";
    std::cin >> n;
    if (n > 0)
    {
        std::cout << "Enter char value\n";
        for (int i = 0; i < n; i++)
        {
            std::cin >> x;
            A.insert(x);
        }
    }

    OrderedLinkedList B;
    std::cout << "Enter size of B: ";
    std::cin >> n;
    if (n > 0)
    {
        std::cout << "Enter char value\n";
        for (int i = 0; i < n; i++)
        {
            std::cin >> x;
            B.insert(x);
        }
    }

    std::cout << "Ordered LL A: \n";
    A.display();
    std::cout << "Ordered LL B: \n";
    B.display();
    std::cout << "\nMerging B in A\n";
    A.merge(B);
    std::cout << "A after merging with B: \n";
    A.display();
    return 0;
}