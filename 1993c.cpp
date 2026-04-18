#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];


    sort(a, a+n);

    int t = a[0];

    for(int i =0;i<n;i++) a[i] -= t;
    int pos =1;

    for(int i =0;i<n;i++){
        if(!(a[i]%k)){pos=0; break;} 
    }
    if(!pos){cout << -1 << '\n'; return;}

    for(int i=0;i<n;i++){
        
    }
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
