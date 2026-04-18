#include <bits/stdc++.h>
#define int long long 
using namespace std;
int ans = 0;
void dfs(int cur, int prev,int p, int s, map<int, vector<int>>& m){
    if(cur == prev) return;
//    cout << cur << " ";
    if(m[cur+p].size() != 0){
        for(auto t:m[cur+p]){
            dfs(cur+s, cur, t, s+t, m);
        }
    }else
    ans = max(ans, s);
}
void solve(){
    int n;
    cin >> n;
    int a[n];

    for(int i =0;i<n;i++) cin >> a[i];
    int b[n];
    map<int, vector<int>>m, g;
    for(int i =0;i<n;i++){
        b[i] = a[i] + i;
        m[b[i]].push_back(i);
    }
    for(int i =0;i<n;i++){
        if(b[i] == n)
        dfs(b[i], -1,i, i, m);
    }
    cout << n + ans << '\n';
    ans = 0;

}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
