#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    

    
    int pref[n+1];
    pref[0] =0;
    map<int, int> m;
    int ans = 0;
    m[0]++;
    for(int i =1;i<n+1;i++){
        pref[i] = pref[i-1] + a[i-1];
        ans += m[pref[i]-x];
        m[pref[i]]++;
    }
    cout << ans;



}
