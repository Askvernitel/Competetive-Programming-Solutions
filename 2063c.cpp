#include <bits/stdc++.h>

using namespace std;

vector<int> dfs(int cur, vector<int>& children[]){ 
    int k = children.size();
    vector<int> t = {0,0};
    for(vector<int> child:children){ 
        dfs(child, children);
    }
    
}

void solve(){
    int n;
    cin >> n;
    vector<int> children[n]
    for(int i=0;i<n;i++){
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
    }
    
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
