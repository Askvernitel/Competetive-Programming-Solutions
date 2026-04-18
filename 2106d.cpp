#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;


    int a[n], b[m];
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<m;i++) cin >> b[i];
    int c = 0;
    int p = n-1;
    bool pos = 1;
    int pref[n+1];
    int suf[n+1];
    pref[0] = 0;
    for(int i =1;i<=n;i++){
        pref[i] = max(pref[i-1], a[i-1]);
    }
    suf[n] = 0;
    for(int i =n-1;i>=0;i--){
        suf[i] = max(suf[i+1], a[i]);
    }
    int u[m+1];
    memset(u, INT_MAX, sizeof(u));
    u[0] = -1;
    for(int i =0;i<m;i++){
        while(c < n){ 
            if(b[i] <= a[c]){
                u[i+1] = c;
                c++;
                break;
            }
            c++;
        }
    }
    int s[m];
    memset(s, -1, sizeof(s));
    for(int i=m-1;i>=0;i--){
        while(p >= 0){
            if(b[i] <= a[p]){
                s[i] = p;
                p--;
                break;
            }
            p--;
        }
    }
    
    int ans = INT_MAX;
    for(int i =0;i<m;i++){
        if(u[i] == INT_MAX) break;
        int cc =u[i];
        if(u[i] < s[i]){
            ans = min(0,ans);
            break;
        }
        if(u[i] <= s[i+1]){
            ans = min(b[i], ans);
        }
    }
    if(ans == INT_MAX){
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
