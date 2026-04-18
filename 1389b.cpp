#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k, z;
    cin >> n >> k >> z;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int f[n];
    memset(f, 0, sizeof(f));

    for(int i =0;i<n-1;i++) f[i] = a[i] + a[i+1];

    int ans = 0;
    for(int i =0;i<=z;i++){
        int mx = 0, r = 0;
       
        for(int j =0;j<(k+1)-2*i;j++){
            mx = max(f[j], mx);
            r += a[j];
        }
        ans = max(mx*i + r, ans);
    }

    cout << ans << '\n';

}
int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}
