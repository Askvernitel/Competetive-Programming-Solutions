#include <bits/stdc++.h>
typedef long double lld;
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    lld t = sqrt(2*double(k) + 0.25) - 0.5;
    int c = ceil(t);
    int sum = (c*(c+1))/2;
    while(n--){
        int zsum = sum;
        int z = c;
        int x;
        cin >> x;
        if(x >= z){
            cout << z << "\n";
            continue;
        }
        zsum -= z;
        int psum = k - zsum;
        z--;
        while(((z)*(x+1))/2 > psum){
            if(z <= x) break;
            zsum -= z;
            z--;
            psum = k-zsum;
        }
        cout << zsum << " ";
        lld p;
        if(z > x) p = double(k)-zsum - (double((z))*double((x+1)))/2;
        else p = double(k)-zsum;
        lld o = p/double(x);
        int v = ceil(o);
        cout << z +v + (z-x) << '\n';

    }

}
