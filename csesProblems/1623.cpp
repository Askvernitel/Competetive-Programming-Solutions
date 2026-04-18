#include <bits/stdc++.h>
#define int long long 
using namespace std;
int ans = INT_MAX;
void solve(int i, int p[], int g1 ,int g2, int n){
    if(i >= n){
        ans = min(abs(g1-g2), ans);
        return;
    }
    solve(i+1, p, g1+p[i], g2, n);
    solve(i+1, p, g1, g2+p[i], n);
}


signed main(){
    int n;
    cin >> n;

    int p[n];

    for(int i =0;i<n;i++) cin >> p[i];
    /*int ans = INT_MAX;
    for(int i =0;i<(1<<n);i++){
        int g1=0, g2 =0;
        for(int j =0;j<n;j++){
            if((i>>j) & 1) g1+=p[j];
            else g2+=p[j];
        }
        ans = min(abs(g1-g2), ans);
    }*/

    solve(0, p, 0, 0, n);
    cout << ans;

}
