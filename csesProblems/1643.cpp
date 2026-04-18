#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int pref[n+1], minvs[n+1];
    int ans = INT_MIN;
    pref[0] = 0;
    minvs[0] = 0;
    for(int i =1;i<=n;i++){
        pref[i] = pref[i-1]+a[i-1];
        minvs[i] = min(minvs[i-1], pref[i]);
        ans = max(pref[i] - minvs[i-1], ans);
    }
    cout << ans;
}
