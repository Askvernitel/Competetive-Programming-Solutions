#include <bits/stdc++.h>
#define int long long
using namespace std;
int N;


void solve(){
    int n;
    cin >> n;
    N=n+1;
    int arr[n];
    for(int i =0;i<n;i++) cin >> arr[i];
    vector<int> a[N];

    for(int i =0;i<n;i++){
        int num;
        cin >> num;
        a[arr[i]].push_back(num);
    }
    for(int i =0;i<N;i++) if(a[i].size() != 0) sort(a[i].begin(), a[i].end(), greater<int>());
    
    for(int i =0;i<N;i++){
        if(a[i].size() != 0){
            int s = 0;
            for(int j =0;j<a[i].size();j++){
                s += a[i][j];
                a[i][j] = s;
            }
        }
    }

    int ans[n];
    memset(ans, 0,sizeof(ans));
    for(int i =0;i<N;i++){
        if(a[i].size() != 0){
            int t = a[i].size();
            int divs[t+1];

            memset(divs, 0, sizeof(divs));
            for(int j = 1;j*j<=t;j++){
                if(!(t%j)){
                    divs[j] = 1;
                    divs[t/j] = 1;
                }
            }
            for(int k = 1;k<=t;k++){
                if(k <= t && !divs[k]) ans[k-1] += a[i][k*(t/k) - 1];
                else if(k<= t && divs[k] == 1) ans[k-1] += a[i].back();

            }

        }
    }

    for(int i =0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << '\n';

}

signed main(){
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int tc; 

    cin >> tc;

    while(tc--) solve();


}
