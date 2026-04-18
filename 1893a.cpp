#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int mark[n];
    memset(mark, 0, sizeof(mark));
    int cur = a[n-1], t = n-1;
    while(!mark[t] && k > 0){
        if(cur > n){cout << "No" << '\n'; return;}
        mark[t] = 1;
        k--;

        t=t-cur;
        if(t < 0) t = n + t;
        cur = a[t];
    }
    cout << "Yes" << '\n';

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
