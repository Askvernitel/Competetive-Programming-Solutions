#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int pref[n+1], suf[n+1];
    suf[n] = INT_MIN;
    for(int i =0;i<n;i++){
        pref[i] = a[i] + (i+1);
        suf[i] = a[i] -(i+1);
    }

    for(int i =1;i<n+1;i++){
        pref[i] = max(pref[i-1], pref[i]);
        suf[n-i] = max(suf[n-i+1], suf[n-i]);
    }
   int ans = 0;
    for(int i =1;i<n;i++){
        ans = max(pref[i-1] + a[i] + suf[i+1], ans);
    }

    cout << ans << '\n';
}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
