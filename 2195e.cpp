#include <bits/stdc++.h>
#define int long long

using namespace std;

int MOD = 1e9 + 7;

int trav(map<int, pair<int,int>>& t, int cur, map<int, int>& acc){ 
        if(t[cur].first == 0 && t[cur].second == 0){
                acc[cur] = 1;
                return acc[cur];
        }


        int l = trav(t, t[cur].first, acc) % MOD;
        int r = trav(t, t[cur].second, acc) % MOD;
        acc[cur] = (l+r+3) % MOD;

        return acc[cur];
}

void trav(map<int, pair<int,int>>& t, int cur, int sum, map<int,int>& acc, map<int,int>& ans){ 
        if(t[cur].first == 0 && t[cur].second == 0){
                ans[cur] = ((sum % MOD) + (acc[cur] % MOD)) % MOD;
                return;
        }
        ans[cur] = (sum  + acc[cur]) % MOD; 
        trav(t, t[cur].first, ((sum % MOD) + (acc[cur] % MOD)) % MOD, acc, ans);
        trav(t, t[cur].second, ((sum % MOD) + (acc[cur] % MOD)) % MOD, acc, ans);
}
void solve(){
        int n;
        cin >> n;
 
        map<int, pair<int, int>> t;
        t[0] = {1, 1};
        for(int i =0;i<n;i++){
                int l, r;
                cin >> l >> r;

                t[i+1] = {l, r};
        }

        map<int,int> acc, ans;
        trav(t, 1, acc);
        trav(t, 1, 0, acc, ans);
        //cout << " "  << ans.size() << '\n';
        for(auto it : ans){ 
                cout << it.second << " ";
        }
        cout << '\n';
        
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
