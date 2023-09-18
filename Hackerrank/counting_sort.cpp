#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int A[n];
    int count[100]={0};
    for(int i =0;i<n;i++){
        cin>>A[i];
        count[A[i]]++;
    }

    for(int i =0;i<100;i++){
        cout<<count[i]<<" ";
    }

    return 0;
}