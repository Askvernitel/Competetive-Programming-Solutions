#include <bits/stdc++.h>

using namespace std;
void solve(){
        int a, b, c;
        cin >> a >> b >> c;

        
        int maxv = max({a, b, c});
        int minv = min({a, b, c});
        int med = a; 
        if(b > minv && b < maxv) med = b;
        if(c > minv && c < maxv) med = c;


        int res = min(med - minv, maxv - med);

        cout << res << "\n";
}
int main(){
        int tc;
        cin >> tc;
        while(tc--) solve();
}
