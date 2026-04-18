#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
        int n;
        cin >> n;
        int a[n], b[n], c[n];
        for(int i =0;i<n;i++){
                cin >> a[i];
        }
        for(int i =0;i<n;i++){
                cin >> b[i];
        }
        for(int i =0;i<n;i++){
                cin >> c[i];
        }

        int A[n], B[n], C[n];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(a[i] < b[j]){ 
                                A[(n+(i-j))%n]++;
                        }
                }
        }
        for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(b[i] < c[j]){ 
                                B[(n+(i-j))%n]++;
                        }
                }
        }

        int cnt1=0, cnt2=0; 
        for(int i =0;i<n;i++){
                if(A[i] == n){ 
                        cnt1+=n;
                }
                if(B[i] == n){ 
                        cnt2++;
                }
        }
        cout << cnt1 * cnt2 << "\n";
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
