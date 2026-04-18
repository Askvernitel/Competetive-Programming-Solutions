#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100002];
int visited[100002];
void dfs(int cur){
    if(visited[cur]) return;
    visited[cur] = 1;

    for(int nei:adj[cur]){
        dfs(nei);
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    for(int i =0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    int s = 0;
    for(int i = 0;i<n;i++){
        if(!visited[i]){dfs(i); ans.push_back(i); s++;} 
    }
    cout << s-1 << '\n';

    for(int i =0;i<ans.size()-1;i++){
        cout << ans[i]+1 << " " << ans[i+1]+1 << '\n';
    }
}
