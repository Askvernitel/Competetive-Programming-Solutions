#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m, k,d;
    cin >> n >> m >> k >> d;
    int river[n][m];
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> river[i][j];
        }
    }

    int costs[n];

    for(int i =0;i<n;i++){
        int c=INT_MAX;
        for(int j =0;j<d;j++){
            river[i][j]++;
        }
        if(d < m) river[i][d]++;
        /*for(int j =m-1;j>=m-j-1;j--){
            river[i][j]++;
        }*/
        for(int j =1;j<m-1;j++){
            river[i][j]++;
        }
        int z[m];
        for(int i =0;i<m;i++) z[i] = INT_MAX;
        z[0] = 1;
        for(int j=0;j<m;j++){
            for(int t=1;t<=d;t++){
                if(j+t >= m) c = min(z[j]+1, c);
                else z[j+t] = min(river[i][j+t] +river[i][j], river[i][j+t]);
            }
        }
        costs[i] = c;
    }

    int ans = INT_MAX;
    int pref[n+1];
    pref[0] = 0;
    for(int i = 1;i<n+1;i++){
        pref[i] = pref[i-1] + costs[i-1];
    }

    for(int i =0;i<n-k+1;i++){
        ans = min(pref[i+k] - pref[i], ans);
    }
    cout << ans << '\n';
    
}


int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}
