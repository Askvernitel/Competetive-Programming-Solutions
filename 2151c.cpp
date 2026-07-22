#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
        int n;
        cin >> n;
        int a[2*n];
        for(int i =0;i<2*n;i++){
                cin >> a[i];
        }


        int I[2*n-1];
        for(int i =0;i<2*n-1;i++){
                I[i] = a[i+1] - a[i];
        }

        int s = 0, p = 1;
        for(int i =0;i<n;i++){
                s += p*I[i];
                p++;
        }
        p--;        
        for(int i =n;i<2*n-1;i++){
                p--;
                s += p*I[i];
        }

        int ans[n];
        for(int i = 0;i<n;i++){
                ans[i] = s;
        }


        int l = n-1, r = n-1;
        
        int fi = 0, se = 0;
        int acc_fi = 0, acc_se = 0;
        int k = 0;
        int move = 0;
        while(l >= 0 && r < 2*n - 1){ 
                int d = (l == r) ? I[l] : I[l] + I[r];
                if(move){
                        ans[k] = s - acc_se - acc_fi; 
                        fi += d;
                        acc_fi += 2*fi;
                }else{
                        ans[k] = s - acc_fi - acc_se; 
                        se += d;
                        acc_se += 2*se;
                }
                
                move = !move;
                r++;
                l--;
                k++;
        }

        for(int i =n-1;i>=0;i--){
                cout << ans[i] << " ";
        }
        cout << '\n';
}
signed main(){ 
        int tc;
        cin >> tc;

        while(tc--) solve();
}
