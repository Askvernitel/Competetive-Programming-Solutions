#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l[k], r[k];
    for(int i =0;i<k;i++) cin >> l[i];
    for(int i =0;i<k;i++) cin >> r[i]; 
    
    map<int,int> m;
    int q; cin >> q;
    while(q--){
        int x;
        cin >> x;
        m[--x]++;
    }

    for(int i =0;i<k;i++){
        int le = l[i]-1, ri = r[i]-1;
        int cnt=0;
        while(ri > le){
            int cntl=m[le], cntr=m[ri];
            cnt += cntl + cntr;
            if(cnt%2){ 
                swap(s[le], s[ri]);
            }
            ri--; le++;
        }
    }
    cout << s << '\n';

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
