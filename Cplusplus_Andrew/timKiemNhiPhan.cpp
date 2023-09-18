#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
bool timKiemNhiPhan(int A[], int n, int x){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(A[mid]==x)
            return true;
        else if(A[mid]>x){
            //tim kiem ben trai
            r = mid -1;
        }
        else if(A[mid]<x){
            l=mid+1;
        }

    }
    return false;
}
bool tkNhiPhan_DeQui(int A[], int l, int r, int x){
    if(l>r)
        return false;
    int mid = (l+r)/2;
    if(A[mid]==x)
        return true;
    else if(A[mid]>x)
        return tkNhiPhan_DeQui(A,l,mid-1,x);
    else
        return tkNhiPhan_DeQui(A,mid+1, r, x);
}
int first_pos(int A[], int n, int x){
    int res=-1;
    int l=0, r=n-1;
    while(l<=r){
        int m = (r+l)/2;
        if(A[m]==x){
            res=m;
            //tim xem con nao phia truoc khong
            r=m-1;
        }else if(A[m]>x){
            //tim ben trai
            r = m-1;
        }else if(A[m]<x){
            //tim ben phai
            l = m+1;
        }
    }
    return res;
}
int last_pos(int A[], int n, int x){
    int res=-1;
    int l=0, r=n-1;
    while(l<=r){
        int m = (r+l)/2;
        if(A[m]==x){
            res=m;
            //tim xem con nao phia sau khong
            l = m+1;
        }else if(A[m]>x){
            //tim ben trai
            r = m-1;
        }else if(A[m]<x){
            //tim ben phai
            l = m+1;
        }
    }
    return res;

}
int main(){
int n;cin>>n;
int A[n];
for(int i =0;i<n;i++){
    cin>>A[i];
}
cout<<last_pos(A, n, 3);

    return 0;
}