#include <bits/stdc++.h>

using namespace std;


void solve(){
    int x;
    cin >> x;

    int k = x/11;

    int p = x%11;

    if(k >= p*10) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}


int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
