#include <bits/stdc++.h>

using namespace std;
int const M = 998244353;
int main(){
    int q,k;
    cin >> q >> k;
    int f[q+1][k+1];
    memset(f, 0, sizeof(f));
    multiset<int> s;
    for(int i =0;i<q;i++){
        f[i][0] = 1;
        char t; int x;
        cin >> t >> x;
        if(t == '+'){
            s.insert(x);
            for(int j = 0;j<k;j++){
                if(f[i][j] && j+x <= k) f[i+1][j+x] = (f[i+1][j+x] + f[i][j])%M;
            }
        }else{
            int p = f[i][x];
            f[i][x]--;
            
            s.erase(s.find(x));
            for(int a:s){
                 if(x+a <= k) f[i][x+a] = f[i][x+a] -1;
            }
            for(int j = 0;j<=k;j++){
                f[i+1][j] = f[i][j];
            }

        }


        cout << f[i+1][k] << '\n';       
    }

}
