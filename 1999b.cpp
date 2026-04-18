#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    int a1, a2, b1, b2;
    int arr[4];
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    if((a1 >= b1 && a2 > b2) || (a1 > b1 && a2 >= b2)) ans++;
    if((a2 >= b1 && a1 > b2) || (a2 > b1 && a1 >= b2)) ans++;
    if((a2 >= b2 && a1 > b1) || (a2 > b2 && a1>=b1)) ans++;
    if((a2 > b1 && a1 >= b2) || (a2 >= b1 && a1 > b2)) ans++;

    cout << ans << '\n';
}    
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
