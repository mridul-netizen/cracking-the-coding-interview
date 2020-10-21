#include<iostream>

using namespace std;

class Stack
{
int top;
public:
    int a[10];//array of 10 integers
    Stack() {
        top = -1; //top of stack is -1
    }

    void push(int x);//initializing methods
    int pop();
    bool isEmpty();
};

void Stack::push(int x) {
    if(top >= 10) {
        cout<<"Stack is Overflow \n";
    }
    else {
        a[++top] = x;
        cout<<"Element "<<x<<" inserted at position:"<<top<<endl;
    }
}

int Stack::pop() {
    if(top < 0) {
        cout<<"Stack is Underflow \n";
        return 0;
    }
    else {
        int d = a[top--];
        return d;
    }
}

bool Stack::isEmpty() {
    if(top < 0){
        return true;
    }
    else {
        return false;
    }
}

class Queue {
    public:
    Stack S1,S2;
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x) {
    S1.push(x);
    cout<<"Element Inserted in Queue\n";
}

int Queue::dequeue() {
    int x, y;
    while(!S1.isEmpty()) {
        x = S1.pop();
        S2.push(x);
    }

    y = S2.pop();//this is for storing -1(i think)
    while(!S2.isEmpty()) {
        x = S2.pop();
        S1.push(x);
    }
    return y;
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(1000);
    //cout<<"Removing element from queue"<<q.dequeue();

    return 0;

}