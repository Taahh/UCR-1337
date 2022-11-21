#include <iostream>

using namespace std;

// Can use both for Circular Linked Lists as well
template<typename T>
class LinkedNode {
public:
    T data;
    LinkedNode<T> *next;
    LinkedNode(T data, LinkedNode<T> *next = nullptr): data(data), next(next) {}
};

template<typename T>
class DoublyLinkedNode {
public:
    T data;
    DoublyLinkedNode<T> *next;
    DoublyLinkedNode<T> *prev;
    DoublyLinkedNode(T data, DoublyLinkedNode<T> *next = nullptr, DoublyLinkedNode<T> *prev = nullptr): data(data), next(next), prev(prev) {}
};

template<typename T>
class LinkedList {
public:
    LinkedNode<T> *head;
    LinkedNode<T> *tail;

    LinkedList<T>(LinkedNode<T> *head = nullptr, LinkedNode<T> *tail = nullptr) : head(head), tail(tail) {
        this->head->next = this->tail;
    }
};

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedNode<T> *head;
    DoublyLinkedNode<T> *tail;

    DoublyLinkedList<T>(DoublyLinkedNode<T> *head = nullptr, DoublyLinkedNode<T> *tail = nullptr) : head(head),
                                                                                                    tail(tail) {
        this->head->next = tail;
        this->tail->prev = this->head;
    }
};

template<typename T>
void print(LinkedList<T> list) {
    auto curr = list.head;
    cout << "[";
    while (curr != nullptr) {
        cout << curr->data;
        if (curr != list.tail) {
            cout << ", ";
        }
        curr = curr->next;
    }
    cout << "]" << endl;
}

template<typename T>
void print(DoublyLinkedList<T> list) {
    auto curr = list.head;
    cout << "[";
    while (curr != nullptr) {
        cout << curr->data;
        if (curr != list.tail) {
            cout << ", ";
        }
        curr = curr->next;
    }
    cout << "]" << endl;
}

template<typename T>
void printReverse(DoublyLinkedList<T> list) {
    auto curr = list.tail;
    cout << "REVERSED [";
    while (curr != nullptr) {
        cout << curr->data;
        if (curr != list.head) {
            cout << ", ";
        }
        curr = curr->prev;
    }
    cout << "]" << endl;
}

void example() {
    // Main Idea, not a full implementation
    cout << "SINGULAR LINKED LIST" << endl;
    {
        LinkedNode<int> *head = new LinkedNode<int>(0);
        LinkedNode<int> *tail = new LinkedNode<int>(1);

        LinkedList<int> list(head, tail);
        print(list);

        {
            //Inserting at the head
            auto temp = list.head;
            list.head = new LinkedNode<int>(-1);
            list.head->next = temp;
            print(list);
        }

        {
            //Inserting at the tail
            list.tail->next = new LinkedNode<int>(2);
            list.tail = list.tail->next;
            print(list);
        }
    }

    cout << endl;
    cout << "DOUBLY LINKED LIST" << endl;

    {
        DoublyLinkedNode<int>* head = new DoublyLinkedNode<int>(0);
        DoublyLinkedNode<int>* tail = new DoublyLinkedNode<int>(1);

        DoublyLinkedList<int> list(head, tail);
        print(list);

        {
            //Inserting at the head
            list.head->prev = new DoublyLinkedNode<int>(-1);
            list.head->prev->next = list.head;
            list.head = list.head->prev;
            print(list);
            printReverse(list);
        }

        {
            // Inserting at the tail
            list.tail->next = new DoublyLinkedNode<int>(2);
            list.tail->next->prev = list.tail;
            list.tail = list.tail->next;
            print(list);
            printReverse(list);
        }
    }


}

int main() {
    example();
}

