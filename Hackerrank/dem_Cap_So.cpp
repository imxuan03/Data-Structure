#include <bits/stdc++.h>
using namespace std;
int check_Cap_So(int A[], int n){
    sort(A,A+n);
    int count =0;
    
    int temp =1;
    for(int i =0;i<n-1;i++){
        
        if(A[i]==A[i+1])
            temp++;
        if(A[i]!=A[i+1]){
            count+=temp/2;
            temp=1;
        }
    }
    return count;
}
int main(){
    int n;cin>>n;
    int A[n];
    for(int i =0;i<n;i++){
        cin>>A[i];
    }
    cout<<check_Cap_So(A, n);
    return 0;
}