using namespace std;

int Result(char c, int a, int b){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}


void evalPostfix(string str){
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int c = (str[i] - '0');
            s.push(c);
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            if(s.empty()) return;
            
            int op2 =s.top(); s.pop();
            int op1 =s.top(); s.pop();
            int result = Result(str[i], op1, op2);
            s.push(result);
        }
        else if(str[i] == ' ' || str[i] == ',') continue;
    }
    int j = s.top();
    cout<<j<<endl;
}



int main()
 {
    int t;
	string str;
	cin>>t;
	for(int i=0;i<t;i++){
	    cin>>str;
	    evalPostfix(str);
	}
	return 0;
}