#include <bits/stdc++.h>

using namespace std;
char grid[51][51];
int pos;
int n, m;
void check(int i, int j){ 
    
    if((i-1 >=0 && grid[i-1][j] == 'G') || (j-1>=0 && grid[i][j-1] == 'G')
    || (i+1 < n && grid[i+1][j] == 'G') || (j+1<m && grid[i][j+1] == 'G')){
        pos = 0;
        return;
    }
    if(i-1 >=0 && grid[i-1][j] == '.'){
        grid[i-1][j] = '#';
    }
    if(i+1 <n && grid[i+1][j] == '.'){
        grid[i+1][j] = '#';
    }
    if(j+1 <m && grid[i][j+1] == '.'){
        grid[i][j+1] = '#';
    }

    if(j-1 >=0 && grid[i][j-1] == '.'){
        grid[i][j-1] = '#';
    }
}
int vis[51][51];
bool dfs(int i, int j){
    if(i < 0 || j < 0  || j>=m || i >=n || grid[i][j] == '#' || vis[i][j]){ 
        return false;
    }
    if(i == n-1 && j == m-1) return true;
    vis[i][j] = 1;
    //cout << dfs(i+1,j) << " " << dfs(i,j+1) << " " << dfs(i-1,j) << " " << dfs(i,j-1) << '\n';
    return dfs(i+1,j) ||
    dfs(i,j+1) || 
    dfs(i-1,j) ||
    dfs(i, j-1);
}
void solve(){
    cin >> n >> m;
    pos = 1;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j] != 'B') continue;
            check(i, j);

        }
    }
    if(!pos){
        cout << "No" << '\n';
        return;
    }

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] != 'G') continue;
            memset(vis,0,sizeof(vis));
            if(!dfs(i, j)) pos = 0;
        }
    }
    if(pos) cout << "Yes" << '\n';
    else{ 
        cout << "No" << '\n';
    }
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
