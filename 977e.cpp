#include <bits/stdc++.h>

using namespace std;
map<int,vector<int>> g;
set<int> visited;
int ans =0;
bool dfs(int cur, int prev, set<int>& vis, int start, int depth){
    if(vis.find(cur) != vis.end()){ 
        return false;
    }
    
    visited.insert(cur);
    vis.insert(cur);
    if(g[cur].size() > 2) return false;
    bool res = false;
    for(int x:g[cur]){ 
        if(x == prev) continue;
        if(depth > 1 && x == start) return true;
        res = res | dfs(x, cur, vis, start, depth+1);
    }
    return res;
}
int main(){
    int n, m;
    cin >> n >> m;

    for(int i =0;i<m;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i =1;i<=n;i++){
        if(visited.find(i) != visited.end()) continue;
        set<int> vis = {};
        if(dfs(i,-1, vis,i, 0)) ans++;
    }
    cout << ans;
}
