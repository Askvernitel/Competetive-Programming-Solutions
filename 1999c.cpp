#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, s, m;
    cin >> n >> s >> m;

    int pr=0;
    bool can = 0;
    for(int i =0;i<n;i++){
        int l, r;
        cin >> l >> r;
        if(l-pr >= s) can = 1;
        pr = r;
    }
    if(m-pr >= s) can = 1;

    if(can) cout << "YES" << '\n'; 
    else cout << "NO" << '\n';
}


int main(){ 
    int tc;

    cin >> tc;

    while(tc--) solve();

}
