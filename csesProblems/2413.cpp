#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int f[n+1];

    f[0] = 0;
    f[1] = 2;
    for(int i =2;i<=n;i++){
        f[i] = 2*f[i-1] + 2*i;
    }
    cout << f[n] << '\n';
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
