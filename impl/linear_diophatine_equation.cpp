#include <bits/stdc++.h>

using namespace std;


int ext_gcd(int a, int b, int& x, int& y){ 
        if(b == 0) {
                x = 1;
                y = 0;
                return a;
        }

        int g = ext_gcd(b, a%b, x, y);
        int x1 = x;
        x=y;
        y=x1 - (b/a)*y;

        return a;
}

void solve(int a, int b, int c){ 
        int x1 = 0, y1 = 0;
        int d = ext_gcd(a, b, x1, y1);


}

int main(){
        int a, b, c;
        cin >> a >> b >> c;
        
        solve(a, b, c);
}
