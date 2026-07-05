#include <bits/stdc++.h>
#define int long long


using namespace std;
int x=1, y=0;


int recursive_gcd(int a, int b){ 
        if(b == 0) return a;

        int g = recursive_gcd(b, a%b);
        int x1 = x;
        x = y;
        y = x1 - ((a/b)*y);
        return g;
}
/*
 * 
 * ax + by = gcd(
 *
 *
 *
 *
 */
signed main(){ 
        int a, b;

        cin >> a >> b;
        while (cin >> a >> b) {
                recursive_gcd(a,b);
                cout << x << " " << y << " "<<recursive_gcd(a, b);
                x=1;
                y=0;
        }
        //cout << x << " " << y << " "<<recursive_gcd(a, b);
        
}
