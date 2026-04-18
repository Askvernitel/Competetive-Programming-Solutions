#include <bits/stdc++.h>

using namespace std;
vector<int> g[3002];
int closed[3002];
void dfs(int ){

}

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i =0;i<m;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    


}
