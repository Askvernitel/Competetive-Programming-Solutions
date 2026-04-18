#include <bits/stdc++.h>

using namespace std;
int m, ans = 0;//, p = 1;
vector<int> g[100002];
int a[100002], vis[100002];
void dfs(int v, int k){
    if(k + a[v] > m) return;
    //if(g[v].size() == 0) return 1;
    int p = 1, s = g[v].size();
    vis[v] = 1;
    for(int i =0;i<s;i++){
       if(!vis[g[v][i]]){dfs(g[v][i], k*a[v] + a[v]); p=0;}
    }
    ans+=p;
   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> m;
    //vector<vector<int>> g(n+1);
    for(int i =1;i<n+1;i++) cin >> a[i];
    
    for(int i =0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    cout << ans;
    
}
