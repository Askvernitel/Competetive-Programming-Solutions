#include <bits/stdc++.h>

using namespace std;
int ans = 0;
void dfs(int cur,map<int,vector<int>>& d, map<int,int>& col, map<int,int>& vis, int color){ 
    if(vis[cur]) return;
    col[cur]=color;
    vis[cur]=1;
    for(int x:d[cur]){ 
        dfs(x, d, col, vis,color);
    }
}
void dfs1(int cur, map<int, vector<int>>& d, map<int,int>& col, map<int,int>& vis, int prev_col){ 
    if(vis[cur]) return;
    vis[cur] = 1;
    if(prev_col != col[cur]) ans++;
    for(int x:d[cur]){ 
        dfs1(cur, d, col, vis, col[cur]);
    }
}
void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    map<int,int> fvis, gvis, gcol;
    map<int,vector<int>> f, g, fcol;
    for(int i = 0;i<m1;i++){
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    for(int i =0;i<m2;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i =1;i<=n;i++){
        dfs(i,g, gcol, gvis, i);
    }
    for(int i = 1;i<=n;i++){
        dfs1(i, f, gcol, fvis, gcol[i]);
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
