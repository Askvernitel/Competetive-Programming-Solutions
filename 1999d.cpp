#include <bits/stdc++.h>

using namespace std;
int const N = 200000;
void solve(){
    string s1, s2;
    
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    //memset(arr, 0, sizeof(arr));
    int p = 0, can = 0;
    for(int i =0;i<n;i++){
        if(p < m && s1[i] == s2[p]){p++;}
        else if(s1[i] == '?'){
            if(p < m) s1[i] = s2[p];
            else s1[i] = 'a';
            p++;
        }
        if(p >= m){can = 1;}
    }

    if(can){cout << "YES" << '\n'; cout << s1 << '\n';}
    else cout << "NO" << '\n';

}
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) solve();
}
