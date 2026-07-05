#include <bits/stdc++.h>

using namespace std;



bool is_good(int* d, int l, int r, int n){ 
        int start_idx = 0;

        for(int i = 0;i<n;i++){
                if(d[i]) {
                        start_idx = i;
                        break;
                }
        }

        for(int i = start_idx;i<start_idx + (r-l+1);i++){
                if(!d[i]) return false;
        }
        return true;
}

void solve(){
        int n;
        cin >> n;

        int a[n];

        for(int i=0;i<n;i++){
                cin >> a[i];
        }
        
        int sz = n/2;

        int mem[n+1][n+1];
        memset(mem, 0, sizeof(mem));
        for(int i =0;i<n;i++){
                int d[n+1];
                memset(d, 0, sizeof(d));
                int am = 0;
                int minv = n+1, maxv = 0;
                for(int j = i;j<n;j++){
                        minv = min(minv, a[j]);
                        maxv = max(maxv, a[j]);
                        am++;
                        d[a[j]]++;
                        if(d[a[j]] > 1){ 
                                break;
                        }
                        if(am == maxv - minv + 1){
                                mem[minv][maxv] = 1;
                        }
                }

        }
        int ans = 0;
        for(int i =n/2;i>=0;i--){
                bool found = false;
                for(int j =1;j<n;j++){
                        if(j+i+1<=n && j+i<=n && j+i+1+i<=n && mem[j][j+i] && mem[j+i+1][j+i+1+i]){
                                found = true;
                                ans = (i+1);
                        }
                }
                if(found) break;

        }
        cout << ans << '\n';
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
