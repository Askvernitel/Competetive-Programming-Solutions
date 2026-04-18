#include <bits/stdc++.h>
#define int long long 
using namespace std;
int arr[202];
signed main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int p = 0;
    for(int i=0;i<n;i++){
        a[i] = a[i]*(i*(n-i) + (n-i));
    }

    sort(a, a+n, greater<int>());
    sort(b, b+n);
    int ans = 0;
    for(int i =0;i<n;i++){
        ans += (a[i]*b[i]); 
    }
    cout << ans;
}
