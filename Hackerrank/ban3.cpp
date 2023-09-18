#include <bits/stdc++.h>

using namespace std;
int main(){
   int n; cin>>n;
   int A[n];
   for(int i =0;i<n;i++){
        cin>>A[i];
   }
    sort(A, A+ n);


    if(A[0]!=A[1])
        cout<<A[0];
    else if(A[n-1]!=A[n-2])
        cout<<A[n-1];
    else{
        for(int i =1;i<n-1;i++){
            if( (A[i-1]!=A[i])&&(A[i]!=A[i+1]) ){
                cout<<A[i];
                break;
            }
        }
    }
    

    return 0;
}