#include <bits/stdc++.h>

using namespace std;
int dfs(int cur, vector<vector<int>>& children, vector<int>& val){
    if(children[cur].size() == 0){ 
        return val[cur];
    }
    int minv = INT_MAX;
    for(int child:children[cur]){
        minv = min(dfs(child, children, val), minv);
    }
    if(cur == 0){ 
        return minv + val[cur];
    }
    if(val[cur] < minv){ 
        int t = (minv-val[cur])/2;

        return min(t+val[cur], minv-t);
    }
    return minv;
}
void solve(){
    int n;

    cin >> n;
    vector<int> val(n);
    vector<vector<int>> children(n);
    for(int i =0;i<n;i++) cin >> val[i];
    for(int i =1;i<n;i++){
        int v; cin >> v;
        children[--v].push_back(i);
    }

    cout << dfs(0,children, val) << '\n';


}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
