#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;

    cin >> n >> k;
    swap(n, k);
    int t = n+k-1;
    int l = n, r = t;
    int v = INT_MAX;
    int ans = INT_MAX;
    int sl = (n*(n-1))/2, sr = (t*(t+1))/2;
    while(l<=r){
        int mid = (l+r)/2;
        int sum = ((mid+1)*mid)/2;
        v = (sum-sl) - (sr - sum);
//        cout << v << " ";
        ans = min(ans, abs(v));
        if(v == 0) break;
        if(v < 0){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << ans << '\n';
}

signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
