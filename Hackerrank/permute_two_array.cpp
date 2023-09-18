#include <bits/stdc++.h>
using namespace std;
int permute()
{
    int n, k;
    cin >> n >> k;
    int A[n];
    int B[n];
    // nhap vao
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    sort(A, A + n);
    sort(B, B + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (A[i] + B[i] < k)
            return 0;
    }
    return 1;
}
int main()
{
    int q;cin>>q;
    int Q[q];
    for(int i =0;i<q;i++){
       Q[i]= permute();
    }
    for(int i =0;i<q;i++){
       if(Q[i]==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}