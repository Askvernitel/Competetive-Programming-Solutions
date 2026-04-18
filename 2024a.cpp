#include <bits/stdc++.h>

using namespace std;
void solve(){
    int a,b;

    cin >> a >> b;


    if(a >= b){ cout << a << '\n'; return;}

    int k = b - a;
    int c = a-k;
    
    if(c > 0){ cout << c << '\n'; return;}

    cout << 0 << '\n';

}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
