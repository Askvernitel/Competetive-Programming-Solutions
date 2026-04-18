#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n+2];
    a[0] = -1; a[n+1] = -1;
    for(int i =1;i<n+1;i++) cin >> a[i];
    int l = 1;
    for(int r = n; r > l;r--){
        if(a[l] == a[l-1] || a[r] == a[r+1]){
            swap(a[l], a[r]);
        }
        l++;
    }
    int ans = 0;
    for(int i =1;i<n+1;i++){
        if(a[i] == a[i+1]) ans++;
    }
    cout << ans << '\n';
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
