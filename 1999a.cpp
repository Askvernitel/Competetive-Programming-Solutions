#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int s = 0;
    while(n != 0){
        s+=(n%10);
        n/=10;
    }

    cout << s << '\n';
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
