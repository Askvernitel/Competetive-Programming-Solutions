#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0, cnt = 0;
    for(int i =0;i<n;i++){
        if(a[i] >= k) ans+=a[i];
        if(a[i] == 0 && ans > 0){ans--; cnt++;}
    }
    cout << cnt << '\n';
}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
