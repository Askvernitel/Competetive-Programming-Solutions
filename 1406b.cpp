#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i =0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans =0, s1=1,s2=1,s3=1, s4=1;
    for(int i =0;i<5;i++){
        s1 *=a[i];
        s3 *=a[n-i-1];
    }

    for(int i =n-1; i>=n-3;i--) s2*=a[i];
    for(int i =0; i <2;i++) s2*=a[i];
    for(int i =0; i<4;i++) s4*=a[i];
    s4*=a[n-1];
    ans = max({s1,s2,s3,s4});
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
