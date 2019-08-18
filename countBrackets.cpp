#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isPair(char open, char close){
    if(open == '(' && close == ')') return true;
    return false;
}

void countBrackets(string str){
    stack<char> s;
    stack<int> p;
    int count = 0;
    string str1 = "";
    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            s.push(str[i]);
            count++;
            p.push(count);
            cout<<count<<" ";
        }
        else if(str[i] == ')'){
            if(isPair(s.top(), str[i])){
                s.pop();
                cout<<p.top()<<" ";
                p.pop();
            }
            else return;
        }
        else continue;
    } 
    cout<<"\n";
}


int main()
 {
    string str;
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>str;
        countBrackets(str);
    }
	return 0;
}