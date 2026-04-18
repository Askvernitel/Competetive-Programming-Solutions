#include <bits/stdc++.h>

using namespace std;

void andout(int a, int b){
    cout << "and " << a << " " << b << '\n';
}
void orout(int a, int b){
    cout << "or " << a << " " << b << '\n';
}
int xorin(int r, int nd){
    return ((~nd) & r);
}
int s(int a, int b){
    int p1, p2;
    andout(a, b);
    cin >> p1;
    orout(a,b);
    cin >> p2;

    int p = xorin(p2,p1);
    return 2*p1 + p;
}


int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int p1, p2, p3;
    p1 = s(1, 2);
    p2 = s(1, 3);
    p3 = s(2, 3);

    a[0] = p1-p3;
    a[0] += p2; a[0]/=2;
    a[2] = p2 - a[0];
    a[1] = p3 - a[2];

    for(int i = 3;i<n;i++){
        a[i] = s(i, i+1) - a[i-1];
    }
    sort(a, a+n);
    cout << "finish "<<a[k-1] << "\n";
    
    fflush(stdout);
    

}
