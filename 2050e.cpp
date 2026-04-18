#include <bits/stdc++.h>

using namespace std;
void solve(){
    string a, b, c;

    cin >> a >> b >> c;
    int n = a.size(), m = b.size();

    int grid[n+1][m+1];
    for(int i =0;i<n+1;i++)
        for(int j =0;j<m+1;j++)
            grid[i][j] = INT_MAX;
    grid[0][0] = 0; 
    
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(j < m){ 
                if(c[i+j] != b[j]){
                    grid[i][j+1]=min(grid[i][j+1], grid[i][j]+1);
                }else{ 
                    grid[i][j+1] = min(grid[i][j+1], grid[i][j]);
                }
            }
            if(i<n){ 
                if(c[i+j] != a[i]){ 
                    grid[i+1][j]=min(grid[i+1][j], grid[i][j]+1);
                }else{ 
                    grid[i+1][j] = min(grid[i+1][j], grid[i][j]);
                }
            }
        }
    }

    cout << grid[n][m]<< '\n';

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
