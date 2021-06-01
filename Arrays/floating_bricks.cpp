#include <bits/stdc++.h>
using namespace std;

int remain(int N){
    

    int var = 1;
    int var1 = 1;
    int i = 0;
    while(var <= N){
        i++;
        var = pow(2,i);
        if(var <= N){
            var1 = var;
        }
    }
    return var1;
}

int main(){
    int n = 16;
    int ans = remain(n);
    cout<<ans<<endl;
}