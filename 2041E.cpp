#include <bits/stdc++.h>

using namespace std;

int main(){ 
    int a, b;

    cin >> a >> b;

    int arr[3];
    int piv1 = 1000, piv2 = -1000;
    int x_plus_y = 3*a - b;

    int x = piv2 + x_plus_y;
    int y = piv1;
    cout << 3 << '\n';
    cout << x << " "<< b << " " << y << '\n';

}
