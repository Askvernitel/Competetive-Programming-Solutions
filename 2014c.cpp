#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    if(n <= 2){ cout << -1 << '\n'; return;}
    sort(a, a+n);
    long double sum=0; 
    for(int i = 0;i<n;i++){
        sum += a[i];
    }
    
    int mid = n/2;
    if(sum/double(2*n) > a[mid]){cout << 0 << '\n'; return;}
//    cout << sum/double(2*n);
    int x = a[mid]*n*2 - sum;
    if(x < 0){cout << -1 << '\n'; return;}
    cout << x+1  << '\n';
}

signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
