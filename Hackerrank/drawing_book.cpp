#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    cin>>n>>p;

    int mid = n/2;
    int result;
    if(p<=mid){
        // if(p%2==0)
        //     p=p+1;

        result = p/2;
    }    
    else{
        // neu le, thi -1
        if(p%2!=0)
            p=p-1;

        result = (n-p)/2;
    }
    cout<<result;
    return 0;
}