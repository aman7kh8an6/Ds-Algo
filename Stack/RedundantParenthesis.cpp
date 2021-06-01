#include<iostream>
#include<stack>
using namespace std;
 //((+))
int redPara(string s){

    stack<char> st;
    int c = 0;
    for(int i = 0; i < s.size(); i++){

        if(st.empty() or s[i] == '(' or s[i] == '*' or s[i] == '+' or s[i] == '-' or s[i] == '/'){
            st.push(s[i]);
        }else{
            if( st.top() == '*' || st.top() ==  '+' || st.top() == '-' || st.top() == '/'){
                c++;
                st.pop();
                st.pop();
            }
        }

    }
    return c;
}

int main(){

    string s = "(((+)*))";
    cout<< redPara(s);
}