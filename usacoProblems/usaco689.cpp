#include <bits/stdc++.h>

using namespace std;

int n;
int grid[15][15];
bool check(){ 
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){ 
                return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("cowtip.in", "r", stdin);

    freopen("cowtip.out", "w", stdout);
    cin >> n;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            char ch;
            cin >> ch;
            grid[i][j] = ch-'0';
        }
    }
    int ans=0;
    while(check()){ 
        int last_row_ind = 0, last_col_ind = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    last_row_ind=i;
                    last_col_ind=j;
                }
            }
        }

        for(int i=0;i<=last_row_ind;i++){
            for(int j=0;j<=last_col_ind;j++){
                if(grid[i][j] == 0){ 
                    grid[i][j]=1;
                }else{
                    grid[i][j]=0;
                }
            }
        }
        ans++;
    }
    cout << ans;
}

