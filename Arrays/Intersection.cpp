#include <bits/stdc++.h>
using namespace std;

int intersect(int a1[], int a2[], int n, int m){
    set<int> s1;
    set<int> s2;
    set<int> s3;
    for(int i  = 0; i < n; i++){
        s1.insert(a1[i]);
    }
    int n1 = s1.size();
    for(int i  = 0; i < m; i++){
        s2.insert(a2[i]);
    }
    int m1 = s2.size();
    for(int i  = 0; i < n; i++){
        s3.insert(a1[i]);
    }
    for(int i  = 0; i < m; i++){
        s3.insert(a2[i]);
    }
    return (n1+m1) - s3.size();
}

int main(){

    int a[] = {1,1,2,2,3,3};
    int b[] = {2,4,5};
    cout<< intersect(a,b,6,3);
    return 0;
}
// mp = [89: 1, 24:1,75:1,11:1,23:1]
// mp = [89: 2, 2:1,4:1]