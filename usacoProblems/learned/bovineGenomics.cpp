#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n,m;
    cin >> n >> m;

    string a[n], b[n];
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];
    int ans = 0;
    int pos = 1;
    for(int i =0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k =j+1;k<m;k++){
                set<string> s;
                string str(3, '#');

                for(int v = 0; v<n;v++){
                    str[0] = a[v][i]; str[1] = a[v][j]; str[2] = a[v][k];
                    s.insert(str);
                }

                for(int v = 0; v<n;v++){
                    str[0] = b[v][i]; str[1] = b[v][j]; str[2] = b[v][k];
                    if(s.find(str) != s.end()){pos = 0; break;}
                    //s.insert(str);
                }
                if(pos) ans++;
                pos = 1;
//                s.clear();
            }

        }

    }
    cout << ans << '\n';

}
