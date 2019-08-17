#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

string InfixToPostfix(string expression){
    stack<char> s;
    string postfix = "";   //empty string
    int l = expression.length();
    bool hasHighPrecedence(char op1, char op2);
    bool isOperator(char c);
    bool isOperand(char c);
    bool isRightAssociative(char op);
    int GetOperatorWeight(char op);
    
    for(int i=0; i<l; i++){
        
        if(expression[i] == ' ' || expression[i] == ',') continue;
        
        
        else if(isOperand(expression[i])){
            postfix += expression[i];
            continue;
        }
        
        else if(expression[i] == '('){
            s.push(expression[i]);
            continue;
        }
        
        else if(expression[i] == ')'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
            continue;
        }
        
        else if(isOperator(expression[i])){
            while(!s.empty() && s.top() != '(' && hasHighPrecedence(s.top(), expression[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);
            continue;
        }
        
        
    }
    while(!s.empty()){
        if(s.top() == '(') s.pop();
        else{
            postfix += s.top();
            s.pop();
        }
    }
        
        return postfix;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
    return false;
}

bool isOperand(char c){
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool isRightAssociative(char op){
    if(op == '^') return true;
    return false;
}

int GetOperatorWeight(char c){
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}

bool hasHighPrecedence(char op1, char op2){
    int w1 = GetOperatorWeight(op1);
    int w2 = GetOperatorWeight(op2); 
    
    if(w1 == w2){
        if(isRightAssociative(op1)) return false;
        return true;
    }
    
    return w1 > w2 ? true : false;
}

int main(){
    string expression;
    cout<<"Enter the Infix expression : ";
    cin >> expression;
    string postfix = InfixToPostfix(expression);
    cout<<"Postfix expression : "<<postfix;
    return 0;
}