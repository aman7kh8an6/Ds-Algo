#include<iostream>
#include<stack>
using namespace std;


bool find(int a[],char c){

    for(int i = 0; i< 3;i++){
        if( a[i] == c){
            return true;
        }
    }
    return false;
}
bool balanceParen(string s){
    bool ans = true;
    stack<char> st;

    for(int i = 0; i<s.length();i++){

        if(s[i] == '{' || s[i] == '(' || s[i]=='['){

            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == '}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == ']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    else{return ans;}
    
}

int main(){

    string s = "{([])}";

    if(balanceParen(s)){
        cout<< "Valid String"<<endl;
    }
    else{
        cout<<"Invalid String"<<endl;
    }
}