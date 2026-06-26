#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n;
        cin >> n;
        int h[n];
        for(int i = 0;i<n;i++){
                cin >> h[i];
        }

        int maxv = h[0];
        int minv = h[0];
        for(int i =0;i<n;i++){
                maxv = max(maxv, h[i]);
                minv = min(minv, h[i]);
        }

        cout << maxv + 1 - minv << '\n';
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
