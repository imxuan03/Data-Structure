#include <bits/stdc++.h>

using namespace std;
long long flipping(unsigned int n){
    int nhiPhan[32];
    // doi n thanh nhi phan
    for (int i = 32 - 1; i >= 0; i--)
    {
        nhiPhan[i] = n % 2;
        n /= 2;
    }
    // chuyen 1->0, 0->1
    for (int i = 0; i < 32; i++)
    {
        if (nhiPhan[i] == 1)
            nhiPhan[i] = 0;
        else
            nhiPhan[i] = 1;
    }
    // tinh ra so he Thap Phan
    long long tong = 0;
    for (int i = 0; i < 32; i++)
    {
        tong += nhiPhan[i]*pow(2,31-i);

    }
    return tong;
}
int main()
{

    int n;
    cin >> n;
    unsigned int A[n];
    for(int i =0;i<n;i++){
        cin>>A[i];
    }
    
    for(int i =0;i<n;i++){
        cout<<flipping(A[i])<<endl;
    }
    return 0;
}