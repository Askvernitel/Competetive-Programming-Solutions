#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s;

    cin >> n >> s;

    if(2*n > s){
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';  
    int p = 0;
    for(int i =0;i<n;i++){
        if(i == n-1){cout << s-p << '\n'; continue;}
        cout << 2 << " ";
        p+=2;
    }
    cout << 1;

}
