#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
        int n;
        cin >> n;

        char a[n];
        char b[n];
        for(int i =0;i<n;i++){
                cin >> a[i];
        }
        for(int i =0;i<n;i++){
                cin >> b[i];
        }

        map<int, set<int>> pos;
        int mod_0=0, mod_1=0;
        for(int i =0;i<n;i++){
                if(a[i] == '1'){
                        pos[i%2].insert(i);
                }
        }
        bool is_pos = 1;
        int ans = 0;
        for(int i =0;i<n;i++){
                if(b[i] == '1'){ 
                        set<int>& s = pos[i%2];
                        if(s.size() == 0){
                                is_pos = 0;
                                break;
                        }
                        auto it = s.lower_bound(i);
                        
                        int val = *it; 
                        if(it == s.end()){
                                it = prev(it);
                                val = *it;
                                ans += (i  - val)/2;
                        }else if(*it == *s.begin()){
                                ans += (val - i)/2;
                        }else{
                                it = prev(it);
                                val = *it;
                                ans += (i  - val)/2;
                        }
                        s.erase(*it);
                }
        
        }
        if(pos[0].size() != 0 || pos[1].size() != 0 || !is_pos){ 
                cout << -1 << '\n';
                return;
        }
        cout << ans << '\n';
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
