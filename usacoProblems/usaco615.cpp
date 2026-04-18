#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m;

    cin >> x >> y >>m;

    int t = m/y, k = m/x;
    int ans = 0;
    for(int i =0;i<=t;i++){
        for(int j =0;j<=k;j++){
            if(j*x + i*y > m) continue;
            ans = max(ans, j*x + i*y);
        }
    }

    cout << ans;

}
