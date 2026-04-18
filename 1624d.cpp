#include <bits/stdc++.h>

using namespace std;
void solve(){

    int n, k;
    cin >> n >> k;


    int cnt[26];
    memset(cnt, 0,sizeof(cnt));
    for(int i =0;i<n;i++){
        char ch; cin >> ch;
        cnt[(int)ch-'a']++;
    }
    int t = 0;
    int p = 0;

    for(int i =0;i<26;i++){
        t+=cnt[i]/2;
        p+=(cnt[i]%2);
    }
    int c = 2*(t%k);
    int d = t/k;
    int u = c+p;
    cout << ((u >= k)?(d*2)+1:d*2) << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
