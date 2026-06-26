#include <bits/stdc++.h>


using namespace std;

int x, y;
int ext_gcd(int a, int b){
        if(b == 0){
                x = a;
                y = 0;
                return a;
        }
        ext_gcd(b, a%b);

        return 0;
}
int main(){
        int n, m, k, a;

        cin >> n >> m >> k >> a;
}
