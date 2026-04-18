#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<n;i++){
        cin >> b[i];
    }
    int ans = 0;
    int t = b[0];
    int prev = 0;
    for(int i =0;i<n;i++){
        if(k-i-1 < 0 ) break;
        int p = a[i] + prev;
        t = max(t, b[i]);
        if(k-i-1 > 0 && i+1 < n && a[i+1] > b[i]){
            p += t*(k-i-2);
            p += a[i+1];
        }else{
            p += t*(k-i-1);
        }
        ans = max(p, ans);
        prev += a[i];
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
