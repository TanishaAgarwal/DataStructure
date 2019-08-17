#include<iostream>
using namespace std;

class Stack {
    public: 
        int data;
        Stack* next;
};

Stack* newNode(int data){
    Stack* temp = new Stack();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int isEmpty(Stack* head){
    return !head;
}

void push(Stack** head, int data){
    Stack* temp = newNode(data);
    temp->next = *head;
    *head = temp;
    cout << data << " pushed to stack\n"; 
}

int pop(Stack** head){
    if(isEmpty(*head)){
        cout<<"Stack UnderFlow!!"<<endl;
        return 0;
    }
    Stack* temp = *head;
    *head = (*head)->next;
    int x = temp->data;
    free(temp);
    return x;
}

int peek(Stack* head){
    if(isEmpty(head)){
        cout<<"Empty!!"<<" ";
        return 0;
    }
    else{
        return head->data;
    }
}

int main(){
    Stack* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 60);
    cout<<pop(&head)<<" popped from stack"<<endl;
    push(&head, 50);
    cout<<pop(&head)<<" popped from stack"<<endl;
    cout<<peek(head)<<" is the top element of the the stack"<<endl;
    cout<<pop(&head)<<" popped from stack"<<endl;
    cout<<pop(&head)<<" popped from stack"<<endl;
    cout<<isEmpty(head)<<endl;
    cout<<peek(head)<<" is the top element of the the stack"<<endl;
    cout<<pop(&head)<<" popped from stack"<<endl;
    cout<<pop(&head)<<" popped from stack"<<endl;
    cout<<isEmpty(head)<<endl;
    cout<<peek(head)<<" is the top element of the the stack"<<endl;
    return 0;
}








