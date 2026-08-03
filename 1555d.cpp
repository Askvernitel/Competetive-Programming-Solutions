#include <bits/stdc++.h>

using namespace std;

array<array<int,3>, 3> sub(int f[3][3], int s[3][3]){ 
        array<array<int,3>, 3> res;

        for(int i = 0; i < 3;i++){
                for(int j = 0; j < 3;j++){
                        res[i][j] = f[i][j] - s[i][j];
                }
        }

        return res;
}

int calc(array<array<int,3>,3> arr){
        int minv = INT_MAX; 
        for(int i =0;i<3;i++){
                for(int j =0;j<3;j++){
                        if(i == j) continue;
                        for(int k =0;k<3;k++){
                                if(i == k || j == k) continue;
                                int cur = 0;
                                for(int t = 0;t<3;t++){
                                        if(t == i) continue;
                                        cur += arr[0][t];
                                }
                                for(int t = 0;t<3;t++){ 
                                        if(t == j) continue;
                                        cur += arr[1][t];
                                }
                                for(int t = 0;t<3;t++){
                                        if(t == k) continue;
                                        cur += arr[2][t];
                                }
                                minv = min(cur, minv);
                        }
                }
        }
        return minv;     
}
void solve(){
        int n,m;
        cin >> n >> m;
        
        int d[n+1][3][3];
        memset(d, 0, sizeof(d));
        for(int i =0;i<n;i++){
                int v = i%3;
                char inp;
                cin >> inp;
                memcpy(d[i+1], d[i], sizeof(d[i+1]));
                d[i+1][v][inp-'a']=d[i][v][inp-'a'] + 1;
        }

        while(m--){ 
                int l, r;
                cin >> l >> r;

                array<array<int,3>, 3> res = sub(d[r], d[l-1]);
/*                for(int i =0;i<3;i++){
                        for(int j =0;j<3;j++){
                                cout << res[i][j] << " ";
                        }
                        cout << '\n';
                }*/
                cout << calc(res) << '\n'; 
        }
}
int main(){
        solve();
}
