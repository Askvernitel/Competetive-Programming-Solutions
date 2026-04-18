#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, m, h;
    cin >> n >> m >> h;
    int a[n][m];
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i =0;i<n;i++) sort(a[i], a[i]+m);
    
    vector<pair<int,int>> points;
    for(int i =0;i<n;i++){
        int c = h;
        int point = 0, penalty = 0;
        int time = 0;

        for(int j =0;j<m;j++){
            if(c >= a[i][j]){
                c-=a[i][j];
                point++;
                penalty += (time+a[i][j]);
                time += a[i][j];
            }else break;
        }
        points.push_back({point, -penalty});
    }
    pair<int,int> rud = points[0];
    int place=n;
    for(int i = 1;i<points.size();i++){
        if(rud >= points[i]){
            place--;
        }
    }
    cout << place << '\n';


}
signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
