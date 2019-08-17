/* Reverse the string using Stack*/

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

void Reverse(char *c, int n){
    stack<char> s;
    for(int i=0; i<n; i++){
        s.push(c[i]);
    }
    for(int i=0; i<n; i++){
        c[i] = s.top();
        s.pop();
    }
}

int main(){
    char str[50];
    cout<<"enter a string : ";
    cin>>str;
    Reverse(str, strlen(str));
    cout<<str;
    return 0;
}