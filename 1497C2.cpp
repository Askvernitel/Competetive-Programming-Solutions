#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n,k;
        cin >> n >> k;

        int a[k];

        for(int i =0;i<k-3;i++){
                a[i] = 1;
        }
        int p = n-(k-3);
        if(p%2 == 1){ 
                a[k-3] = 1;
                a[k-2] = p/2;
                a[k-1] = p/2;
        }else if(p%4 == 0){
                a[k-3] = p/2;
                a[k-2] = p/4;
                a[k-1] = p/4;
        }else if(p%2 == 0){ 
                a[k-3] = p/2 - 1;
                a[k-2] = p/2 - 1;
                a[k-1] = 2;
        }

        for(int i =0;i<k;i++){
                cout << a[i] << " ";
        }
        cout << "\n";
}
int main(){ 
        int tc;
        cin >> tc;

        while(tc--) solve();
}
