#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c;

    cin >> a >> b >> c;

    if(c-1 != a){cout << -1 << '\n'; return;}
    int ans = 0;
    if((b%c>c/2 && c%2) || (b%c>0 && !(c%2))) ans++;
    ans+=b/c;

    while(c != 1){
        
        ans+=(c%2);
        c/=2;
        ans++;
    }

    cout << ans << '\n';

}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
