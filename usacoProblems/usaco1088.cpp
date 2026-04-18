#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int grid[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    int r=0, c=0;
    for(int i =0;i<n;i++){
        int row=0, col=0;
        int tmp_row=0, tmp_col = 0;
        for(int j = 0;j<n;j+=2){
            tmp_row += grid[i][j];
            tmp_col += grid[j][i];
        }
        for(int j = 1;j<n;j+=2){ 
            row += grid[i][j];
            col += grid[j][i];
        }

        r += max(row, tmp_row);
        c += max(col, tmp_col);

    }

    cout << max(r, c);
}
