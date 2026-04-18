#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, r, x;

    cin >> n >> l >> r >> x;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int ans = 0;
    for(int i =0;i<(1<<n);i++){
        int s=0;
        int mx=0, mn = INT_MAX;
        for(int j = 0;j<n;j++){
            if(i>>j & 1){s += a[j]; mx=max(mx,a[j]); mn = min(mn, a[j]); }
        }
        if(mx - mn >= x && s >= l && s <=r) ans++;
    }

    cout << ans;
}
