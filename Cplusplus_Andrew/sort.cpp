#include <bits/stdc++.h>
using namespace std;
void selectionSort(int A[], int n){
    int min_pos;
    for(int i =0;i<n-1;i++){
        min_pos =i;
        for(int j =i+1;j<n;j++){
            if(A[min_pos]>A[j])
                min_pos=j;
        }
        swap(A[i], A[min_pos]);
    }
}
void bubbleSort(int A[], int n){
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(A[j]>A[j+1])
                swap(A[j],A[j+1]);
        }
    }

}
void countingSort(int A[], int n){
    int cnt[100000];
    //dem tan so va tim max 
    int m =INT_MIN;
    for(int i =0;i<n;i++){
        cnt[A[i]]++;
        if(A[i]>m)
            m = A[i];
    }
    for(int i =0;i<=m;i++){
        if(cnt[i]!=0){
            for(int j =0;j<cnt[i];j++){
                cout<<cn
            }
        }
    }
    


}

int main(){
    int n;cin>>n;
    int A[n];
    for(int i =0;i<n;i++){
        cin>>A[i];
    }
    bubbleSort(A, n);
    for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}