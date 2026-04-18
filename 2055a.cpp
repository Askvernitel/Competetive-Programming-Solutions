#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, a,b;
    cin >> n >> a >> b;
    
    if((abs(a-b)-1)%2){ 
        cout << "YES\n";

    }else{ 
        cout << "NO\n";
    }

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
