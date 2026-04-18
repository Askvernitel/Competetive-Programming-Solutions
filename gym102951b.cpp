#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    sort(a, a+n);
    int j = 0;
    while(j < n && x >= a[j] ) x-=a[j++];

    cout << j << '\n';
}
