#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    cin.ignore(1);
    string strings[n];

    //nhap string
    for(int i =0;i<n;i++){
        getline(cin, strings[i]);
    }
    
    int m;cin>>m;
    cin.ignore(1);
    string queries[m];

    //nhap queries
    for(int i =0;i<m;i++){
        getline(cin, queries[i]);
    }

    int A[m];

    //xet su trung lap nhau
    for(int i =0;i<m;i++){
        //1 ptu queries, duyet qua het tat ca ptu strings
        int count =0;
        for(int j = 0;j<n;j++){
            if(queries[i]==strings[j])
                count++;

        }
        A[i]=count;
    }
    for(int i =0;i<m;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}