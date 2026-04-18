#include <bits/stdc++.h>

using namespace std;

bool h(int a, int b){ 
    return (a > 0 && b > 0) || (a < 0 && b < 0);
}
void solve(){
    int n, s;
    cin >> n >> s;
    int ans = n;
    for(int i =0;i<n;i++){
        int dx, dy;
        cin >> dx >> dy;

        int x, y;
        cin >> x >> y;
        if(x+y == s || x == y){ 
            int px = s-x, py =s-y;
            if(h(px, dx) && h(py,dy) && abs(px) == abs(py)){ 
                continue;
            }
            px = -x;py=s-y;
            if(h(px, dx) && h(py,dy) && abs(px) == abs(py)){ 
                continue;
            }
            px = s-x, py=-y;
            if(h(px, dx) && h(py,dy) && abs(px) ==abs(py)){ 
                continue;
            }
            px = -x, py =-y;
            if(h(px, dx) && h(py,dy) && abs(px) == abs(py)){ 
                continue;
            }
            ans--;
        }else{ 
            ans--;
        }
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
