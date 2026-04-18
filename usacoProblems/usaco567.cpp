#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int k = b-a;
    int t = d-c;
    int inter = max(min(d,b)-max(a,c), 0);
    cout << k + t - inter;
}
