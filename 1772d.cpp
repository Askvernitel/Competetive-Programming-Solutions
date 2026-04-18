#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    

    int minv = INT_MAX;
    for(int i =0;i<n-1;i++){
        if(a[i] < a[i+1]){
            minv = min(minv, (a[i]+a[i+1])/2);
        }
    }
    int ans = 0;
    for(int i =0;i<n-1;i++){
        if(a[i] > a[i+1]){
            int p = ((a[i+1] + a[i])%2)?(a[i+1]+a[i])/2+1:(a[i+1]+a[i])/2;
            ans = max(p, ans);
        }
    }

    if(ans > minv) ans = -1;

    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
