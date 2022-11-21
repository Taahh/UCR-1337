// nullptr will represent empty
#include <stdexcept>
#include <iostream>
#include "../linkedlist/LinkedList.cpp"

using namespace std;

template <typename T>
class ArrayBasedStack {
private:
    int capacity;
    T *array;
    int top;
public:
    ArrayBasedStack(int capacity): capacity(capacity) {
        this->array = new T[capacity];
        this->top = 0;
    }

    int peek() {
        return this->array[this->top-1];
    }

    int pop() {
        if (this->top <= 0) {
            throw underflow_error("Can't over pop!");
        }
        return this->array[--this->top];
    }

    int size() {
        return this->top;
    }

    void print() {
        cout << "[";
        for (int i = 0; i < this->top; i++) {
            cout << this->array[i];
            if (i != this->top - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void push(T value) {
        if (this->top >= this->capacity) {
            throw overflow_error("Can't over push!");
        }
        this->array[this->top++] = value;
    }
};

template<typename T>
class LLBasedStack {
private:
    DoublyLinkedNode<T>* head;
    int length;
public:
    LLBasedStack(DoublyLinkedNode<T>* head = nullptr): head(head) {
        this->length = 0;
    }

    int peek() {
        return this->head->data;
    }

    int pop() {
        if (this->head == nullptr) {
            throw underflow_error("Can't over pop!");
        }
        auto temp = this->head->data;

        this->head = this->head->prev;
        if (this->head != nullptr) {
            this->head->next = nullptr;
        }
        this->length--;
        return temp;
    }

    int size() {
        return this->length;
    }

    void print() {
        cout << "[";
        auto curr = this->head;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->prev != nullptr) {
                cout << ", ";
            }
            curr = curr->prev;
        }
        cout << "]" << endl;
    }

    void push(T value) {
        if (this->head == nullptr) {
            this->head = new DoublyLinkedNode<T>(value);
            return;
        }

        this->head->next = new DoublyLinkedNode<T>(value);
        this->head->next->prev = this->head;
        this->head = this->head->next;
    }
};


int main() {
    try {
        LLBasedStack<int> stack;
        stack.push(1);
        stack.print();
        cout << "PEEK: " << stack.peek() << endl; // Should return 1
        cout << "POP: " << stack.pop() << endl; // Should remove 1
//        stack.pop(); // Oh! we can't go under 0, should throw error
        stack.print();

        for (int i = 0; i < 20; i++) {
            stack.push(i);
        }

        stack.print();

//        stack.push(20); // Can't go over 20, should throw error for array based stack
        cout << "PEEK: " << stack.peek() << endl; // Should return 19
        cout << "POP: " << stack.pop() << endl; // Should remove 19
        stack.print();



    } catch (const underflow_error& e) {
        cout << e.what() << endl;
    } catch (const overflow_error& e) {
        cout << e.what() << endl;
    }
}
