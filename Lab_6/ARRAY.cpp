#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Stack {
  private:
    int* items;
    int capacity;
    int top;
    
  public:
    Stack(int capacity) {
        this->capacity = capacity;
        top = -1;
        items = new int[capacity];
    }
    
    bool is_empty() {
        return top == -1;
    }
    
    bool is_full() {
        return top == capacity - 1;
    }
    
    void push(int x) {
        if (is_full()) {
          cout<< "Stack overflow"<<endl;
        } else {
          top++;
          items[top] = x;
        }
    }

    int pop() {
        if (is_empty()) {
           cout<< "Stack underflow"<<endl;
           return -1;
        } else {
           int x = items[top];
           top--;
           return x;
        }
    }   
    
    int stack_top() {
        if (is_empty()) {
            cout<< "Stack is empty"<<endl;
        }
        return items[top];
    }
    
    void display() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements:";
            for (int i = top; i >= 0; i--) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
    
    int size() {
        return top + 1;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;
    auto startTime = chrono::high_resolution_clock::now();
    Stack s(capacity);
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