#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;

    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    map<int, int> m;
    int ans = 0;
    for(int i =0;i<n;i++){
        m[a[i]-i] += a[i];
        ans = max(m[a[i]-i], ans);
    }
    /*for(int it =m.begin();i!=it.end();i++){
        
    }*/
    cout << ans << '\n';
}
