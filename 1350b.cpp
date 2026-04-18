#include <bits/stdc++.h>

using namespace std;
void solve(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    for(int i =1;i<=n;i++) cin >> a[i-1];
    int f[n+1];

    for(int i =0;i<=n;i++){
        f[i] = 0;
    }

    for(int i =1;i<=n;i++){
        f[i-1] = max(f[i-1], 1);
        for(int j=i+i;j<=n;j+=i){
            if(a[i-1] < a[j-1]) f[j-1] = max(f[i-1] + 1, f[j-1]);
        }
    }
    int ans = 0;

    for(int i =0;i<n;i++) ans = max(ans, f[i]);
    cout << ans << '\n';

}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

