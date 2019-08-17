/* C++ program to implement basic stack operations  using ARRAY*/

#include<iostream>
using namespace std;
const int MAX = 101;
class Stack {
    int top;
    public: 
        int a[MAX];
        Stack():top(-1){}
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x){
    if(top >= MAX-1){
        cout<<"Stack Overflow!!"<<endl;
        return false;
    }
    else{
        a[++top] = x;
        cout<<x<<" is pushed in to the Stack"<<endl;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout<<"Stack Underflow!!"<<endl;
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top < 0){
        cout<<"Empty!!"<<endl;
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0)?true:false;
}

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(60);
    cout<<s.pop()<<" popped from stack"<<endl;
    s.push(50);
    cout<<s.pop()<<" popped from stack"<<endl;
    cout<<s.peek()<<" is the top element of the the stack"<<endl;
    cout<<s.pop()<<" popped from stack"<<endl;
    cout<<s.pop()<<" popped from stack"<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.peek()<<" is the top element of the the stack"<<endl;
    cout<<s.pop()<<" popped from stack"<<endl;
    cout<<s.pop()<<" popped from stack"<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.peek()<<" is the top element of the the stack"<<endl;
    return 0;
}








