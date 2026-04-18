#include <bits/stdc++.h>

using namespace std;
vector<int> langs[104];
vector<int> emps[104];
int vis[104];
int vis1[104];
void dfs(int cur){
    vis1[cur] = 1;
    for(int x:emps[cur]){ 
//        if(vis[x]) continue;
//        vis[x] = 1;
        for(int p:langs[x]){ 
            if(vis1[p]) continue;
            vis1[p] = 1;
            dfs(p);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int ans=0;
    for(int i =0;i<n;i++){
        int k;
        cin >> k;
        if(k != 0) ans = -1;
        for(int j=0;j<k;j++){
            int v;
            cin >> v;
            emps[i].push_back(v);
            langs[v].push_back(i);
        }

    }
    for(int i =0;i<n;i++){ 
        if(vis1[i]) continue;
        ans++;
        dfs(i);
        
    }
   cout << ans;

}
