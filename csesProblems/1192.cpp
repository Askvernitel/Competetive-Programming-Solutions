#include <bits/stdc++.h>

using namespace std;
int const N = 1001, M = 1001;

int n, m;
int visited[N][M];
int a[N][M];
void dfs(int i, int j){
    if(i < 0 || i >= n  || j <  0 || j >= m 
        || visited[i][j] || !a[i][j]){
        return;
    }
    visited[i][j] = 1;

    dfs(i + 1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
}
int main(){
    cin >> n >> m;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            char ch; cin >> ch;
            if(ch == '#') a[i][j] = 0;
            else a[i][j] =1;
        }
    }
    

    int ans =0;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(!a[i][j] || visited[i][j]) continue;
            dfs(i,j);
            ans++;
        }
    }
    cout << ans;

}
