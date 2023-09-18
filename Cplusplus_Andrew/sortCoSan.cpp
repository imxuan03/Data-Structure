#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b){
    //dieu kien, minh muon cho dieu kien gi cung duoc
    return abs(a)<abs(b);
}
int main(){
// int n;
// cin>>n;
// pair<int,int> a[n];
// for(int i =0;i<n;i++){
//     cin>>a[i].first>>a[i].second;
// }
// sort(a,a+n);
// for(auto it : a){
//     cout<<it.first<<" "<<it.second<<endl;
// }

    int n;cin>>n;
    int A[n];
    for(int i =0;i<n;i++){
        cin>>A[i];
    }
    stable_sort(A, A+n, cmp);
       for(int i =0;i<n;i++){
       cout<<A[i]<<" ";
    }

}