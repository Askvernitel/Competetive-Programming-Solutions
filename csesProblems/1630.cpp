#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i =0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);
    int t=0;
    int ans = 0;
    for(int i =0;i<n;i++){
        t+=a[i].first;

        ans+=a[i].second-t;
    }
    cout << ans << '\n';

}
