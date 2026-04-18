#include <bits/stdc++.h>

using namespace std;
int n;
int indegsum = 0;
vector<int> outdegs[101];
int indeg[101];
void dfs(int cur, int par){
    indegsum+=indeg[cur];
    for(int outdeg:outdegs[cur]){
        dfs(outdeg, cur);
    }
}

int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    cin >> n;
    for(int i =0;i<n-1;i++){
        int v1, v2;
        cin >> v1 >> v2;
        indeg[v2]++;
        outdegs[v2].push_back(v1);
    }

    int ans = -1;
    for(int i =1;i<=n;i++){
        dfs(i, -1);
        if(indegsum == n-1){ans = i; break;}
        indegsum = 0;
    }

    cout << ans;

}
