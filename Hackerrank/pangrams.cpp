#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);

    int A[26]={0};
    //bien tat ca cac chu thanh chu thuong
    for(int i =0;i<s.length(); i++){
        if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
    }
    
    for(int i = 0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z')
            A[(s[i]-97)]++;
    }
    
    for(int i =0;i<26;i++){
        cout<<A[i]<<" ";
    }

    //vong for xet, neu co A[i]=0, ==>not pangram
    int flag =1;
    for(int i =0;i<26;i++){
        if(A[i]==0){
            flag =0;
            break;
        }
    }
    if(flag)
        cout<<"pangram";
    else
        cout<<"not pangram";

    return 0;
}