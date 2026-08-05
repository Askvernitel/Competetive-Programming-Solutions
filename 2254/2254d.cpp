#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
        int n;

        cin >> n;

        int b[n];
        map<int, int> m;
        for(int i =0;i<n;i++){
                cin >> b[i];
                m[b[i]]++;
        }
        
        map<int, int> mp;

        if((*m.begin()).first != 0){ 
                cout << -1 << '\n';
                return;
        }
        auto it = m.begin();
        int prev_val = 0;
        int acc = 0;
        while(it != m.end()){
                if(next(it) == m.end()){
                        mp[(*it).first] = prev_val + 1;
                        break;
                }
                int next_val = (*next(it)).first - acc;
                int val = (*it).first;
                int cnt = (*it).second;
                if(next_val%cnt){ 
                        cout << -1 << "\n";
                        return;
                }
                mp[val]=next_val/cnt;
                if(next_val/cnt <= prev_val){ 
                        cout << -1 << "\n";
                        return;
                }
                prev_val = next_val/cnt; 
                acc+=next_val;
                it = next(it);
        }

        for(int i =0;i<n;i++){
                cout << mp[b[i]] << " ";
        }
        cout << '\n';

        
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
