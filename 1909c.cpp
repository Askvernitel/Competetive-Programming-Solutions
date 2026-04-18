#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){ 
    int n;
    cin >> n;
    int l[n], r[n], c[n];
    set<int> ls, rs;
    for(int i =0;i<n;i++){
        cin >> l[i];
    }
    for(int i =0;i<n;i++){
        cin >> r[i];
        rs.insert(r[i]);
    }
    for(int i =0;i<n;i++){
        cin >> c[i];
    }
    sort(l,l+n,greater<int>());
    sort(c,c+n);
    int dist[n];
    for(int i = 0;i<n;i++){
        auto it = rs.lower_bound(l[i]);
        dist[i] = (*it) - l[i];
        rs.erase(it);
    }
    sort(dist,dist+n, greater<int>());
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans += dist[i]*c[i];
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
