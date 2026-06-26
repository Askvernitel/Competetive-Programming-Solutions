#include <bits/stdc++.h>

using namespace std;



void solve1(){
        int n, m, k; 

        cin >> n >> m >> k;

        int dl = 0, dr = 0;
        int ans = 1;

        int p_cost_dl = 0, p_cost_dr = 0;
        while(k - dl > 1 || k + dr < n){

                if(p_cost_dl + p_cost_dr > m){
                        break;
                }
                int cost_dl = (k - dl > 1) ? (dl + 1) + dr + max(dr, dl + 1) - 1 : INT_MAX;
                int cost_dr = (k + dr < n) ? (dr + 1) + dl + max(dr + 1, dl) - 1 : INT_MAX;
                
                if(cost_dl < cost_dr){
                        p_cost_dl = cost_dl;
                        dl++;
                }else{
                        p_cost_dr = cost_dr;
                        dr++;
                }

                ans++;
        }
        cout << ans << '\n';
} 
int f(int n, int k, int m){
        return 2*n + min(n, k-1) - 1 ;
}
void solve(){
        int n, m, k; 

        cin >> n >> m >> k;
 
        int max_side = max(n-k, k-1);
        //int min_side = min(n-k, k-1);
        
 
        int l = -1, r = max_side+1;
        int t = 0; 
        while(l + 1 < r){ 
                int mid = (r+l)/2;
                if(f(mid, k, m) <= m){ 
                        l = mid;
                        t = f(mid, k, m); 
                }else{
                        r = mid;
                }
        }
 
        f(l,k,m); 
        cout << 1 + min(n-k, max(0,l)) + min(k-1, max(0,l)) << '\n';
}
int main(){
        int tc;
        cin >> tc;


        while(tc--) solve();
}
