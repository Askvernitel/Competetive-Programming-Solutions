#include <bits/stdc++.h>

using namespace std;
int grid[3000][3000];
int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n;
    cin >> n;
    map<int,pair<int,int>> dirs ={ 
        {(int)'N',{0,1}},
        {(int)'E',{1,0}},
        {(int)'S',{0,-1}},
        {(int)'W',{-1,0}}
    };
    int a[n][2];
    for(int i =0;i<n;i++){
        char ch;
        int num;
        cin >> ch >> num;
        a[i][0] = (int)ch;
        a[i][1] = num;
    } 
    
    int pos_x = 1500;
    int pos_y = 1500;
    int time = 0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        int dx = dirs[a[i][0]].first, dy = dirs[a[i][0]].second;
        
        while(a[i][1] != 0){ 
            if(grid[pos_x][pos_y] != 0){
                ans = min(time-grid[pos_x][pos_y], ans);
            }
            grid[pos_x][pos_y]=time;
            pos_x+=dx;
            pos_y+=dy;
            time++;
            a[i][1]--;
        }
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans;


}
