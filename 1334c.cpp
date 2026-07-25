#include <bits/stdc++.h>


using namespace std;
void solve(){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0;i < n;i++){
                cin >> a[i] >> b[i];
        }
        int dt[n];
        dt[n-1] = a[n-1];
        for(int i =0;i<2*n;i++){
                int best_t = dt[(n+i-1)%n];
                int prev_b = b[(n+i-1)%n];
                int cur = i%n;
                dt[cur] = max(min(best_t + (a[cur] - prev_b), a[cur]), a[cur]);
                cout << dt[cur] << " ";
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
                ans = max(dt[i], ans);
        }
        cout << ans << '\n';
}

int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
