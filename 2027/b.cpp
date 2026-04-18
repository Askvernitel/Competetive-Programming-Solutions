#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;

    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int ans = INT_MAX;

    for(int i =0;i<n;i++){
        int res = i;
        int maxv = a[i];
        
        for(int j =i+1;j<n;j++){
            if(maxv < a[j]){
                res++;
            }
        }
        ans = min(ans, res);
    }

    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) solve();
}
