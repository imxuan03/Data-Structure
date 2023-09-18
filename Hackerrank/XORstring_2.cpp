#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s,t;
  
    getline(cin, s);
    getline(cin, t);
    string res="";
    for(int i =0;i<s.length();i++){
        if( s[i]==t[i])
            res+='0';
        else
            res+='1';

    }
    cout<<res;
    return 0;
}
