#include <bits/stdc++.h>

using namespace std;
void solve(){
    int x,y,k;

    cin >> x >> y >> k;

    int c = x/k;
    int b = y/k;

    cout << c + b + abs(b-c) << '\n';
    

}


int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
