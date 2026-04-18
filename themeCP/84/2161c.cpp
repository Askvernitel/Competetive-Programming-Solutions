#include <bits/stdc++.h>
#define int long long
using namespace std;

#define ADD_MOD(a, b, mod) ((a + b)%mod)


void solve(){ 
        int n, x;

        cin >> n >> x;
        int a[n];
        for(int i=0;i<n;i++){
                cin >> a[i];
        }
        
        sort(a,a+n);
        int sum = 0; 
        int last_index = n-1;
        int ans = 0;

        vector<int> out;
        for(int i=0;i<=last_index;i++){
                while(last_index >= i && x - sum <= a[last_index]){ 
                        out.push_back(a[last_index]);
                        ans += a[last_index];
                        sum = ADD_MOD(sum, a[last_index--], x);
                        //out.push_back(m[a[i]].second[m[a[i]].first++]);
                }
                if(last_index < i) continue;
                out.push_back(a[i]);
                sum = ADD_MOD(sum, a[i], x);
        }
        if(out.size() < n){
        }
        cout << ans << '\n';
        for(int o:out){ 
                cout << o << ' ';
        }
        cout << '\n';
}
signed main(){
        int tc;

        cin >> tc;

        while(tc--) solve();
}
