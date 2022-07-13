#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isRedundant(string input){
    stack<char> s;
    bool isOperator = false;
    for(char ch:input){
        switch(ch){
            case ')':
                while(s.top()!='('){
                    if(s.top() == '+' or s.top()=='-' or s.top()=='/' or s.top()=='*'){
                        isOperator = true;
                    }
                    s.pop();
                }
                s.pop();
                if(!s.empty()){
                    isOperator = false;
                }
                break;
            default:
                s.push(ch);
                break;
        }
    }
    if(isOperator){
        return false;
    }
    return true;
}



int main(){
    string s = "((a+b)+c)";
    if(isRedundant(s)){
        cout << "Redundant" <<endl;
    }
    else{
        cout << "Not Redundant" <<endl;
    }
    return 0;
}