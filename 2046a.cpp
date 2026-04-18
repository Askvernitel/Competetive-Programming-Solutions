#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];
    int ans = INT_MIN;
    for(int i =0;i<n;i++){
        int v=a[i]+b[i];
        int cur = v;
        for(int j =0;j<n;j++){
            if(j == i) continue;
            if(a[j] > b[j]) cur+=a[j];
            else cur += b[j];
        }
        ans = max(cur, ans);
    }
    
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
