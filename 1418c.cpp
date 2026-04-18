#include <bits/stdc++.h>

using namespace std;
void solve(){
    int inf = 1e9;
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int f[n+4];

    for(int i =0;i<n+1;i++) f[i] = inf;
    f[0] = 0;
    for(int i =0;i<n;i++){
        f[i+1] = min(f[i]+a[i], f[i+1]);
        f[i+2] = min(f[i]+a[i], f[i+2]);
        f[i+3] = min(f[i]+a[i], f[i+3]);
    }   
    cout << f[n] << '\n';
}


int main(){
    int tc;

    cin >> tc;
    while(tc--) solve();

}
