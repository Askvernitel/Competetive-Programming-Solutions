#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        char ch;
        cin >> ch;
        a[i] = (ch)-48;
    }

    int pref[n+1];
    pref[0] =0;
    for(int i=1;i<n+1;i++) pref[i] = a[i-1]+pref[i-1];
    map<int,int> cnt;
    for(int i=0;i<n+1;i++){
        cnt[pref[i] - i]++;
    }
    int ans =0;
    for(auto &x:cnt){
        int p = x.second;

        ans+=((p)*(p-1))/2;
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
