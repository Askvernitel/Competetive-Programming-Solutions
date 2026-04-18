#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;
signed main(){
    int n;

    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int b[n];
    for(int i=0;i<n;i++){
        int maxv = 0;
        for(int j=i;j<n;j+=(i+1)){
            maxv = max(maxv, a[j]);
        }
        b[i] = maxv;
    }

    sort(b, b+n);
   int sum=0;
    int prev=0;
    for(int i=0;i<n;i++){
        sum = (sum%mod + (((prev+1)%mod)*b[i])%mod)%mod;
        prev =(2*(prev%mod) + 1)%mod;
    }

    cout << sum << '\n';
    
}
