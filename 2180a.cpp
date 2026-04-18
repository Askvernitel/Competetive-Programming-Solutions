#include <bits/stdc++.h>

using namespace std;
void solve(){
    int l, a, b;

    cin >> l >> a >> b;

    int ans = 0; 
    for(int i =0;i<l;i++){
        ans = max((a+i*b)%l, ans);
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
