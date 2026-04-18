#include <bits/stdc++.h>

using namespace std;
void solve(){
    int x, y;
    cin >> x >> y;

    int k = 9;
    while(x+1 >= 1){ 
        if(x+1 == y){
            cout << "YES\n";
            return;
        }
        x-=k;
    }

    cout << "NO\n";
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
