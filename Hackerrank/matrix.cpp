#include <bits/stdc++.h>

using namespace std;
int diagonalDifference(int n, int A[100][100]){
    //tinh theo chieu xuoi
    //VD
    // 0 0 - 1 1 - 2 2
    //xet theo chieu nguoc
    // 2 0 - 1 1 - 0 2
    int chieuXuoi = 0;
    int chieuNguoc =0;

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){           
            if(i==j)
                chieuXuoi+=A[i][j];
            
            if(j==(n-1-i))
                chieuNguoc+=A[i][j];
        }
    }
    return abs(chieuNguoc-chieuXuoi);

}

int main(){
    int n;cin>>n;
    int A[100][100];
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>A[i][j];
        }
    }
    cout<<diagonalDifference(n, A);

    return 0;
}