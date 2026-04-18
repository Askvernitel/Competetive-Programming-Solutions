#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int n;

    cin >> n;

    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int ans = INT_MIN;
    int sum = 0;
    for(int i =0;i<n;i++){
        
        sum = max(sum+a[i], a[i]);
        ans = max(ans, sum);
    }

    cout << ans;

}
