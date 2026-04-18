#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    map<int, int> cnt;
    int a[n], b[n];
    for(int i =0;i<3;i++){
        for(int j =0;j<n;j++){
            if(i == 0){ 
                cin >> a[j];
            }else if(i == 1){ 
                cin >> b[j];
            }else{ 
                int t;
                cin >> t;
                cnt[b[t-1]]++;
            }
        }
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        ans +=cnt[a[i]];

        
    }
    cout << ans << '\n';
}
