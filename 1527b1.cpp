#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int k =0;
    char s;
    for(int i=0;i<n;i++){
        char ch;
        cin >> ch;
        if(ch == '0') k++;
        if(i == n/2) s = ch;
    }
    //11111
    if(s=='0' && k != 1 && k%2) cout << "ALICE" << '\n';
    else if(k==1) cout << "BOB" << '\n';
    else if(!(k%2)) cout << "BOB" << '\n';
    else cout << "DRAW" << '\n';

}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

} 
