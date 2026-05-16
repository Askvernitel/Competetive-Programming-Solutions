#include <bits/stdc++.h>

using namespace std;

int x, y;

void gcd(int a, int b){ 
        if(!a){
                x = 0;
                y = 1;
                return;
        }
        

        gcd(b%a, a);

        int x1 = y;
        y = x - (y * (b/a));
        x = x1;

}


int main(){ 
        int a, b;
        cin >> a >> b;


        gcd(a,b);

        cout << x << " " << y << "\n";
}
