#include <bits/stdc++.h>

using namespace std;
int const N = 100001;
int f[N], p[N];
int M = 1e9 + 7;
int main(){
    int t, k;
    cin >> t >> k;
    
    f[0] = 1;
    for(int i =0; i<N;i++){
        if(i+k < N) f[i+k]= (f[i+k]%M + f[i]%M)%M;
        f[i+1]= (f[i+1]%M + f[i]%M)%M;
    }
    for(int i =1;i<N;i++) p[i] = (p[i-1] + f[i])%M;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (p[b]-p[a-1]+M)%M<<'\n';
        

    }

}
