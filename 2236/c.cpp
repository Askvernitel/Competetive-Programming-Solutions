#include <bits/stdc++.h>

using namespace std;
void solve(){
        int a, b, x;

        cin >> a >> b >> x;

        
        vector<int> a_div, b_div;

        int ca = a, cb = b;
        while(ca != 0){ 
                a_div.push_back(ca);
                ca /= x;
        }

        while(cb != 0){ 
                b_div.push_back(cb);
                cb /= x;
        }

        a_div.push_back(0);
        b_div.push_back(0);

        int ans = INT_MAX; 
        for(int i =0;i<a_div.size();i++){
                for(int j =0;j<b_div.size();j++){
                        ans = min(abs(a_div[i]-b_div[j]) + (i+j), ans);
                }
        }
        cout << ans << '\n';
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();

}
