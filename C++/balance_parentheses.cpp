#include <stack>
#include <iostream>
using namespace std;

string x;

int balance(string x){
    stack<char> stk;
    int len = x.length();
    for (int i = 0; i < len; i++){
        
        if (x[i] == '(' || x[i] == '{' || x[i] == '['){
            stk.push(x[i]);
        }
        if (x[i] == ')' || x[i] == '}' || x[i] == ']'){
            if (stk.empty()){
                return 0;
            }
            if (x[i] == ')' && stk.top() == '('){
                stk.pop();
            }
            else if (x[i] == ']' && stk.top() == '['){
                stk.pop();
            }
            else if (x[i] == '}' && stk.top() == '{'){
                stk.pop();
            }
            else {
                return 0;
            }
        }
    }
    if (stk.empty()){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    cin >> x;
    if (balance(x)){
        cout << "Brackets are balanced.\n";
        return 0;
    }
    cout << "Brackets are unbalanced.\n";
}
