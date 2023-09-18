#include <bits/stdc++.h>
using namespace std;
int check(vector<int>a){
    sort(a.begin(), a.end());
    int n=a.size();
    int B[n];
    for(int i =0;i<n/2;i++){
        B[i]=a[i];
    }

    int k =n-1;
    for(int i =((n/2)+1)-1;i<n;i++){
        B[i]=a[k];
        k--;
    }
 
    for(int i =0;i<n;i++){
        cout<<B[i] <<" ";
    }
}
int main(){
    int t;cin>>t;
    vector<int> a[t];

    //nhap cac 1 mang cac vector
    for(int i =0;i<t;i++){
        int m;cin>>m;
        for(int j = 0;j<m;j++){
            int x;cin>>x;
            a[i].push_back(x);
        }
    }
    for(int i =0;i<t;i++){
        check(a[i]);
        cout<<"\n";
    }
    return 0;
}