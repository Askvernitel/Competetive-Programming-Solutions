#include <bits/stdc++.h>

using namespace std;
void solve(){
    int l1, b1,l2,b2,l3,b3;

    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    int p = l2+l3;
    if(p == l1) {
        if(b2 == b3){ 
            int c = b3+b1;
            if( c==l1) { 
                cout << "YES\n" ;
                return;
            }
        }
    }
    int c = b2+b3;
    if(c == b1){ 
        if(l2 == l3){ 
            int p = l1+l2;
            if(p ==b1){ 
                cout << "YES\n";
                return;
            }
        }
    }
    if(b1 == b2 && b2 == b3){ 
        if(l1+l2+l3 == b3){
            cout << "YES\n";
            return;
        }
    }
    if(l1 == l2 && l2 == l3){ 
        if(b1+b2+b3 == l3){ 
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
