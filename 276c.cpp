#include <bits/stdc++.h>
#define int long long
using namespace std;

int const N = 200001;
int sum[N];
signed main(){
    int n, q;

    cin >> n >> q;

    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        sum[l]++;
        sum[r+1]--;
    }
    sort(a, a+n);
    int t = 0;
    for(int i =0;i<n;i++){
        t+=sum[i];
        sum[i] = t;
    }

    sort(sum, sum+n);

    int ans = 0;
    for(int i =0;i<n;i++){
        ans += a[i]*sum[i];
    }

    cout << ans;


}
