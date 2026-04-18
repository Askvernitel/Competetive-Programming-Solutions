#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;

    int a[n], b[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    for(int i =0;i<n;i++){
        cin >> b[i];
    }
    bool is_even = ((k%2) == 0);
    int maxv = 0;
    int cur_max = 0;
    for(int i =0;i<n;i++){
        if(!is_even){ 
            cur_max = max(b[i], cur_max);
        }

        if(maxv + a[i] < 0){ 
        }
    }
}
int main(){ 
    int tc;
    cin >> tc;

    while(tc--) solve();
}
