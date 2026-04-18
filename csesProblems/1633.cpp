#include <bits/stdc++.h>

using namespace std;
int M = 1e9+7;
int main(){
    int n;
    cin >> n;
    int f[n+1];
    for(int i =0;i<n+1;i++){
        f[i] = 0;
    }
    f[0] = 1;
    for(int i =0;i<n;i++){
        for(int j =1;j<=6;j++){
            if(i+j <= n) f[i+j] = (f[i+j] + f[i])%M; 
        }
    }
    cout << f[n];
}
