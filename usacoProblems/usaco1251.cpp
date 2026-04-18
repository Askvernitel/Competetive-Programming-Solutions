#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    int a[n];

    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    sort(a,a+n, greater<int>());
    int ans = 0, idx = 0;
    for(int i =0;i<n;i++){
        if(ans <= a[i]*(i+1)){

            ans =a[i] * (i+1);
            idx =a[i];
        }
    }
    cout << ans << " " << idx;
}
