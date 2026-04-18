#include <bits/stdc++.h>

using namespace std;

void solve(){
    int inf = 1e9;
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int f[n+1];
    for(int i =0;i<n+1;i++) f[i] = inf;
    f[0] = 0;

    for(int i =0;i<n;i++){
        if(i+a[i]+1 > n){f[i+1] = min(f[i] + 1, f[i+1]);}
        else{
            f[i+a[i]+1] = min(f[i], f[i+a[i] + 1]);
            f[i+1] = min(f[i]+1,f[i+1]);

        }
    }

    cout << f[n] << '\n';

}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
