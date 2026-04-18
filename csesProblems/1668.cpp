#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100002];
int colors[100002];
int visited[100002];
int pos = 1;
void dfs(int cur, int color){
    if(visited[cur] && colors[cur] != color){
        pos = 0;
        return;
    }
    if(visited[cur]) return;
    colors[cur] = color;
    
    visited[cur] = 1;
    for(int nei:adj[cur]){
        dfs(nei, !color);
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

    for(int i = 0;i<n;i++){
        if(!visited[i]){dfs(i, 1);}
    }
    if(!pos){
        cout << "IMPOSSIBLE";
        return 0 ;
    }
    for(int i =0;i<n;i++){
        cout << colors[i] + 1 << " ";
    }

}
