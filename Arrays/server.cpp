#include <bits/stdc++.h>
using namespace std;

int get_usage( int m,int k,vector<int> v){

    priority_queue <int, vector<int>, greater<int>> pq(v.begin(), v.end());
    for(int i = 0; i<m; i++){
        int t = pq.top();
        pq.pop();
        t = t+1;
        pq.push(t);
    }

    while(k>1){
        pq.pop();
        k--;
    }
    return pq.top();
}
int main(){

    vector<int> v = {5,9,3,6,4,3};

    cout<< get_usage(7,2,v);
}