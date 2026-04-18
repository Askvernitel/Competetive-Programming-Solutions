#include <bits/stdc++.h>

using namespace std;
vector<int> children[200002];
int ans[200002];
int dfs(int cur, int par){
    if(children[cur].size() <= 1) return 1;
    int res = 0;
    for(int child:children[cur]){
        if(child != par){
            res+=dfs(child,cur); 
        }
    }
    ans[cur] = res;
    return res+1;

}
int main(){
    int n;
    cin >> n;
    children[0].push_back(-1);
    for(int i = 1;i<n;i++){
        int v;
        cin >> v;
        
        children[--v].push_back(i);
        children[i].push_back(v);
    }
    
    dfs(0, -1);
    for(int i =0;i<n;i++){
        cout << ans[i]<< " ";
    }
}
