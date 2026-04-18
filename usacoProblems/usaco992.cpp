#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> children[1002];
int visited[1001];
int maxv = 0;
void dfs(int cur, int prev, int s, int minw){
    if(cur == s){
        maxv = max(minw,maxv);
        return;
    }
    for(auto child: children[cur]){
        if(!visited[child.first]){
            visited[child.first] = 1;
            dfs(child.first, cur, s,  max(minw, child.second));
        }
    }
    return;



}
int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;

    cin >> n >> m;
    int a[n];
    vector<int> wrong;
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) if(a[i]-1 != i){wrong.push_back(i);};
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;

        a--;b--;

        children[a].push_back({b, w});
        children[b].push_back({a, w});


    }
    int ans = INT_MAX, minw = 0;
    for(int i =0;i<wrong.size();i++){
        maxv = 0;
        dfs(wrong[i], -1, a[wrong[i]], minw);
        ans = min(maxv, ans);
        minw = 0;
        maxv = 0;
        memset(visited, 0, sizeof(visited));
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans << '\n';
    




}
