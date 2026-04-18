#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;
    int ex1=x1, ey1=y1, ex2=x2, ey2=y2;
    for(int i =0;i<n;i++){
        char t;
        int r;
        char s;

        cin >> t >> r >> s;

        if(t == 'V'){ 
            if(s=='L'){
                ex1=max(ex1,min(ex2,r));
            }else{
                ex2=min(ex2,max(ex1,r));
            }
        }else{
            if(s=='T'){
                ey2=min(ey2,max(r,ey1));
            }else{
                ey1=max(ey1,min(r, ey2));
            }
        }
    }
    cout << abs(ex2-ex1)*abs(ey1-ey2) << '\n';
}
