#include <bits/stdc++.h>
using namespace std;

int main(){
string s = "hello nguyen thanh xuan";
stringstream ss(s);
string temp;
while(getline(ss, temp,' ')){
    cout<<temp<<endl;
}

    return 0;
}