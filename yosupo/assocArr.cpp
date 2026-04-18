#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int q;
    cin >> q;
    map<int, int> m;
    while(q--){
        int t;
        cin >> t;

        if(t){
            int d;
            cin >> d;
            cout << m[d] << '\n';
        }else{
            int d, c;
            cin >> d >> c;
            m[d] = c;
        }
    }


}
