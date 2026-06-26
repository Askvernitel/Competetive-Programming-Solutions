#include <bits/stdc++.h>


using namespace std;
int x, y;
int _gcd(int a, int b, int& x, int& y){ 
        x = 1, y = 0;
        int x1 = 0, y1 = 1, a1 = a, b1 = b;
        while(b1 != 0){
                int q = a1/b1;
                tie(x, x1) = make_tuple(x1, x - (q*x1));
                tie(y, y1) = make_tuple(y1, y - (q*y1));
                tie(a1, b1) = make_tuple(b1, a1%b1);
        }

        return a1;
}
int main(){
        int a, b;
        cin >> a >> b;
        cout << _gcd(a, b, x, y) << '\n';

        cout << "X:" << x << "Y:" << y << '\n';
}
