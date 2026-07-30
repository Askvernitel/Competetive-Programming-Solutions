#include <bits/stdc++.h>
#define int long long 

using namespace std;


int a[300000], b[300000];
void solve(){
        int n;
        cin >> n;

        for(int i =0;i<n;i++){
                cin >> a[i] >> b[i];
        }

        int ans = 0, minv = 1e18;        
        for(int i =0;i<n;i++){
                int next_i = (i + 1)%n;
                ans += max((a[next_i] - b[i]),(int)0);
                minv = min(min(b[i],a[next_i]) , minv);
        }

        cout << ans + minv << "\n";
}


signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie();
        int tc;
        cin >> tc;

        while(tc--) solve();
}
