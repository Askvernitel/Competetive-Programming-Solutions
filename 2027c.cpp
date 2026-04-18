#include <bits/stdc++.h>

#define int long long
using namespace std;
int dfs(map<int, vector<int>>& m, int cur, map<int,int>& dp){ 
    if(m[cur].size() == 0) return cur;
    if(dp[cur]) return dp[cur];
    int mx = 0;

    for(int v:m[cur]){ 
        mx = max(dfs(m, cur+v,dp), mx);
    }

    dp[cur]=mx;
    return dp[cur];
}

void solve(){
    int n;
    cin >> n;
    int a[n];

    map<int,vector<int>> m;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    map<int ,int> dp;
    for(int i = 1;i<n;i++) m[a[i] + i].push_back(i);
    int ans = 0;
    ans = max(dfs(m,n,dp), ans);
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
