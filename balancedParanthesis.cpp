/* Check for balanced parentheses in an expression using stack */

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

bool arePair(char open , char close){
    if(open == '(' && close == ')') return true;
    else if(open == '{' && close == '}') return true;
    else if(open == '[' && close == ']') return true;
    return false;
}

bool areParanthesisBalanced(string expression){
    stack<char> s;
    for(int i=0; i<expression.length(); i++){
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            s.push(expression[i]);
            continue;
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            if(!arePair(s.top(), expression[i]) || s.empty()) return false;
            else s.pop();
        }
    }
    
    return s.empty() ? true : false;
}


int main(){
    string expression;
    cout<<"Enter the Paranthesis to check whether they are Balanced : ";
    cin >> expression;
    if(areParanthesisBalanced(expression)){
        cout<<"Balanced!!"<<endl;
    }
    else{
        cout<<"Not Balanced!!"<<endl;
    }
    return 0;
}