#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    int a[n];

    for(int i = 0; i<n; i++}{
        cin>>a[i];
    }

    int max1 = a[0];
    int max2 = a[0];
    for(int i = 0;i<n;i++){
        if (max1 < a[i])
        {
            max1 = a[i];
            a[i] = 0;
        }
    }
    for(int i = 0;i<n;i++){
        if (max2 < a[i])
        {
            max2 = a[i];
            a[i] = 0;
        }
    }
    cout<<max1*max2<<endl;
}