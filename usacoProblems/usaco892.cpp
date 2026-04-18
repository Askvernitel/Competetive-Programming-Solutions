#include <bits/stdc++.h>

using namespace std;

int main(){ 
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i =n-1;i>0;i--){
        if(a[i] < a[i-1]){
            break;
        }
        cnt++;
    }
    cout << n - cnt-1;
}
