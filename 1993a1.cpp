#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; string s;
    cin >> n;
    cin >> s;
    int a[4];
    memset(a, 0, sizeof(a));
    for(int i =0;i<4*n;i++){
        
        if(s[i] != '?'){
            a[s[i]-'A']++;
        }
    }
    int ans = 0;

    for(int i =0;i<4;i++){
        if(a[i] > n) ans += n;
        else ans+=a[i];
    }

   // ans+=a[4];

    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    int tc;

    cin >> tc;

    while(tc--) solve();

}

