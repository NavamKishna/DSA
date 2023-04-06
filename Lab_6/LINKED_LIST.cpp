#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
private:
    StackNode* top;

public:
    Stack() {
        top = NULL;
    }

    bool is_empty() {
        return top == NULL;
    }

    void push(int x) {
        StackNode* new_node = new StackNode(x);
        new_node->next = top;
        top = new_node;
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack underflow" << endl;
            return -1;  // Return -1 as an error value
        }
        int x = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    int stack_top() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return -1;  // Return -1 as an error value
        }
        return top->data;
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
        } else {
            StackNode* temp = top;
            cout << "Stack elements: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s; // Create a new stack object
    auto startTime = chrono::high_resolution_clock::now();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);

    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    
    s.display();

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    cout << "Time taken : " << duration << " ms \n" ;
    
}

