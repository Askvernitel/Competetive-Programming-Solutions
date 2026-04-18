#include <bits/stdc++.h>

using namespace std;
void solve(){
    int inf = 1e9;
    int n , k;
    cin >> n >> k;

    int a[n+1];
    a[n] = inf;
    for(int i =0;i<n;i++) cin >> a[i];

    int l = 0, r=0;
    int ans = 0;
    while(r<n){
        if(r-l+1 == k+1){
            ans++;
            l++;
        }else if(a[r+1]*2 > a[r]){
            r++;
        }else{ 
            r++;
            l=r;
        }

    }
    cout << ans << '\n';
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
