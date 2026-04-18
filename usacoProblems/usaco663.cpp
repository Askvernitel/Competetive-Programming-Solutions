#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int k = min({x1,x2,x3,x4});
    int p = max({x1,x2,x3,x4});
    int t = min({y1,y2,y3,y4});
    int u = max({y1,y2,y3,y4});

    int a = max((p-k),(u-t));

    cout << a*a;
}
