#include <bits/stdc++.h>

using namespace std;
int grid[102][102];
void solve(){
    int n;
    cin >> n;

    for(int i =0;i<n;i++){
        int w, h;

        cin >> w >> h;

        for(int j =1;j<=h;j++){
            for(int k = 1;k<=w;k++){
                grid[j][k] = 1;
            }
        }
    }
    int ans =0;
    for(int i =0;i<101;i++){
        for(int j = 0;j<101;j++){
            if(grid[i][j] == 1){
                if(grid[i-1][j] == 0) ans++;
                if(grid[i][j-1] == 0) ans++;
                if(grid[i+1][j] == 0) ans++;
                if(grid[i][j+1] == 0) ans++;
            }
        }

    }

    cout << ans << '\n';
    memset(grid, 0, sizeof(grid));
}

int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) solve();
}
