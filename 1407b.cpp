#include <bits/stdc++.h>

#define skip continue

using namespace std;

int gcd(int a, int b){
        return (a != 0) ? gcd(b%a, a) : b;
}

pair<int,int> get_max_gcd(int* a, int n, int v){ 
        int g = 1;
        int res_ind;
        for(int j =0;j<n;j++){
                if(a[j] == -1) skip;
                int potential_g = gcd(v, a[j]);
                if(g <= potential_g){ 
                        g = potential_g;
                        res_ind=j;
                }
        }
        return {g, res_ind};
}

void solve(){ 
        int n;
        cin >> n;

        int a[n];

        for(int i =0;i<n;i++){
                cin >> a[i];
        }
        
        int g = 1;
        int ind_1;
        for(int i =0;i<n;i++){
                if(a[i] >= g){ 
                        g = a[i];
                        ind_1=i;
                }
        }
        cout << a[ind_1] << " ";
        a[ind_1] = -1;

        for(int i =0;i<n-1;i++){
                auto [next_g, j] = get_max_gcd(a, n, g);
                cout << a[j] << " ";
                a[j] = -1;
                g=next_g;
        }
        cout << '\n';
}
int main(){

        int tc;
        cin >> tc;

        while(tc--) solve();
}
