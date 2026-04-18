#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b){ 
        if(a == 1 || b == 1) return 1; 
        unsigned int shift = __builtin_ctz(a | b);

        a >>= shift;
        b >>= shift;
        while(b != 0){ 
                a >>= __builtin_ctz(a);
                b >>= __builtin_ctz(b);

                if(b > a) {
                        swap(a, b);
                }
                a = a-b;
        }
        
        return a << shift;
}



int main(){ 
        int a, b;
        cin >> a >> b;
        int d =gcd(a, b);
        std::gcd()
        cout << d << '\n';
}
