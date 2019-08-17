#include<iostream>
#include<stack>
using namespace std;

class Node  
{  
    public: 
        int data;  
        Node *next;  
}; 

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void Insert(Node** head, int data){
    Node* temp = newNode(data);
    if(*head == NULL){
        *head = temp;
        return; 
    }
    
    Node* p = *head;
    
    while(p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    return;  
}

void Reverse(Node** head){
    stack<Node*> s;
    Node* temp = *head;
    while(temp != NULL){
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    *head = temp;
    s.pop();
    while(!s.empty()){
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void Print(Node* head){
    if(head == NULL){
        cout<<"Empty List!!"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
     return;
}

int main(){
    Node* head = NULL;
    Insert(&head, 10);
    Insert(&head, 20);
    Insert(&head, 30);
    Insert(&head, 40);
    Insert(&head, 50);
    Print(head);
    Reverse(&head);
    Print(head);
    return 0;
}