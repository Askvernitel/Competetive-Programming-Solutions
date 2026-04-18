#include <bits/stdc++.h>

using namespace std;
void solve(){
    string r;
    cin >> r;

    int n = r.size();
    int cons = 0;
    int ans = 0;
    if(r[0] == 'u'){
        ans++;
        r[0] = 's';
    }
    if(r[n-1] == 'u'){
        ans++;
        r[n-1] = 's';

    }
    for(int i =1;i<n;i++){
        if(r[i] == r[i-1] && r[i] == 'u'){
            cons++;
        }else{
            ans+=((cons+1)/2);
            cons = 0;

        }
    }
    ans+=((cons+1)/2);
    cout << ans << '\n';
}
int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}
