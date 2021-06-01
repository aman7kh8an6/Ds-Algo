#include<iostream>
#include<stack>
using namespace std;

void calSpan(int arr[], int n, int S[]){

    stack<int> st;

    st.push(0);
    S[0] = 1;
    for(int i = 1; i<n;i++){
        
        while(!st.empty() && arr[st.top()] <= arr[i]){

            st.pop();
        }
        if( st.empty()){
            S[i] = i+1;
        }else{
            S[i] = i - st.top();
        }
        st.push(i);
    }
}
void printArray(int arr[], int n)
{   
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){

    int arr[] { 1,6,2,5 };
    int n = 4;
    int S[n];
    calSpan(arr,n,S);
    printArray(S,n);
}