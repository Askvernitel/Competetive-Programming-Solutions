#include <bits/stdc++.h>
#define int long long

using namespace std;
#define LAST_INDEX 100
int primes[1000];
int first_primes[LAST_INDEX + 1];
void erat(){ 
        memset(primes, 1, sizeof(primes));
        for(int i=2;i<1000;i++){
                if(primes[i] == 0){
                        continue;
                }
                for(int j = i+i;j<1000;j+=i){ 
                        primes[j] = 0;
                }
        }
        int last_index = 0;
        for(int i =2;i<1000;i++){ 
                if(last_index == LAST_INDEX){
                        break;
                }
                if(primes[i]){
                        first_primes[last_index++]=i;
                }
        }
}
void solve(){ 
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
                cin >> a[i];
        }
        int ans = INT_MAX;
        for(int i =0;i<n;i++){
                for(int j=0;j<LAST_INDEX;j++){
                        if(a[i]%first_primes[j] != 0){
                                ans = min(first_primes[j], ans);
                                break;
                        }
                }
        }

        cout << ans << '\n';
}
signed main(){ 
        int tc;
        erat();
        cin >> tc;
        while(tc--) solve();

}
