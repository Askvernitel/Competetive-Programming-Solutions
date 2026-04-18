#include <bits/stdc++.h>

using namespace std;
int k, n, x, t=0;
void solve(){
    int dist = 0;
    int left = 0;
    t=0;
    for(int i=1;;i++){
        dist += i;
        t++;
        if(dist + left >= k){
            return;
        }

        if(i >= x){
            t++;
            left+= i;
            if(dist + left>=k) return;
        }
    }
}
int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> k >> n;

    while(n--){
        cin >> x;
        solve();
        cout << t << '\n';
    }
}
