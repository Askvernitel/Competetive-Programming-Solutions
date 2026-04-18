#include <bits/stdc++.h>
#define int long long
using namespace std;

int road[100001];
signed main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin >> n >> k >> b;
    for(int i = 0;i<b;i++){ 
        int num;
        cin >> num;
        road[--num]=1;
    }

    int pref[n+1];
    pref[0]=road[0];
    for(int i =1;i<n+1;i++){
        pref[i] = pref[i-1] + road[i-1];
    }
    int ans = b;
    for(int i =0;i<=n-k;i++){
        ans = min(ans, pref[i+k]-pref[i]);
    }
    cout << ans << '\n';

}
