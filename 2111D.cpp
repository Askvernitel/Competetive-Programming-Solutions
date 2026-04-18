#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;

    int a[m];
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    sort(a,a+m);
    int mv = 0;
    int t = 0;

    for(int i =0;i<n;i++){ 
        mv=!mv;
        for(int j=0;j<6;j++){
            if(mv){ 
                cout << a[t] << " ";
            }else{ 
                cout << a[m-t-1] << " ";
            }
            mv = !mv;
        }
        if(!((i+1)%2)) t++;
        cout << '\n';
    }

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
