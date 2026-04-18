#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    int t = n - k + 1;

    if(k==1 && !(n%2)){
        cout << "YES" << '\n';
        return;
    }
    if(n <= k && !(n%4)){cout << "YES" << '\n'; return;}
    if(n <= k && (n%2) && n-3 >= 0 && !((n-3)%4)){cout << "YES" << '\n'; return;}
    if( n>=k && !(k%4)){cout << "YES" << '\n'; return;}
    if((n>=k) && (n%2) && k-3>=0 &&  !((k-3)%4)){cout << "YES" << '\n'; return;}
    cout << "NO" << '\n'; 
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
