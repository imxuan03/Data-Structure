#include <bits/stdc++.h>

using namespace std;
int main()
{

    // int n = 5;
    // long long A[5];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> A[i];
    // }
    // sort(A, A + 5);
    // //min
    // long long sumMIN =0;
    // for(int i =0;i<4;i++){
    //     sumMIN += A[i];
    // }
    // long long sumMax = 0;
    // for(int j =n-1;j>0;j--){
    //     sumMax += A[j];
    // }

    // cout<<sumMIN<<" ";
    // cout<<sumMax<<endl;
    string s = "hello minh la nguyen thanh xuan";
    stringstream ss(s);

    string tmp;
    while(getline(ss, tmp,' ')){
        cout<<tmp<<endl;

    }
    return 0;
}
