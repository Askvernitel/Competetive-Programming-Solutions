#include <bits/stdc++.h>

using namespace std;


void solve(){
   freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin >> n;
    int deg[n+1];
    memset(deg, 0, sizeof(deg));
    for(int i = 0;i<n-1;i++){
        int v1, v2;
        cin >> v1 >> v2;
        deg[v1]++;
        deg[v2]++;
    }
    int maxv = 0;
    int ans = 1;
    for(int i =1;i<n+1;i++) maxv = max(deg[i], maxv);
    ans+=maxv;
    cout << ans;
}

int main(){
    solve();
}
