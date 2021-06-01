#include <bits/stdc++.h>
using namespace std;

vector<int> merge(int a[], int b[], int n, int m){
    map<int, int> mp;
    vector<int> v;
    for(int i = 0; i<n; i++){
        mp[a[i]]++;
    }
    for(int i = 0; i<m; i++){
        mp[b[i]]++;
    }

    for(auto i:mp){
        for(auto j = 0; j < i.second;j++){
            v.push_back(i.first);
        }
    }
    return v;
}
// first = 1,2,4,6,9,10,11,12
// second = 1,3,1,1,1,1,1,1

int main(){

    int a[] = {1,2,2,2,10};
    int b[] = {4,6,9,11,12};
    vector<int> ans;
    ans = merge(a,b,5,5);
    for(int i = 0; i< ans.size(); i++){
        cout<< ans[i] << " ";
    }
    return 0;
}