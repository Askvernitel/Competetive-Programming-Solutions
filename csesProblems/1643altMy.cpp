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
        if(sum + a[i] < 0){sum = 0; }
        sum += a[i];
        ans = max(sum, ans);
    }
 
    cout << ans ;
}
