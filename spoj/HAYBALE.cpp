#include <bits/stdc++.h>


using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    int a[n+1];
    memset(a,0,sizeof(a));
    for(int i =0;i<k;i++){
        int l,r;
        cin >> l >> r;
        l--;
        a[l]++;
        a[r]--;
    }
    int t=0;
    for(int i =0;i<n+1;i++){
        t+=a[i];
        a[i] = t;
    }
    sort(a, a+n);
    cout << a[n/2];
}
