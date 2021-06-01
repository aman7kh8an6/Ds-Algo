#include <bits/stdc++.h>
using namespace std;

int vowel(string s){
    int c = 0;
    for(int i = 0; i< s.length();i++){
        
        if( s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
            c++;
        }
        if( s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
            c++;
        }
    }
    return c;
}

int main(){

    string s = "bcd";
    int ans;
    cout<< vowel(s);
    // cout<<ans<<endl;
}