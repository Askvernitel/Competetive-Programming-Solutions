#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;

    cin >>n >> q;
    int pref[n+1][3];
    pref[0][0] = 0;
    pref[0][1] = 0;
    pref[0][2] = 0;
    for(int i =1;i<n+1;i++){
        int type;
        cin >> type;    
        pref[i][0] = pref[i-1][0];
        pref[i][1] = pref[i-1][1];
        pref[i][2] = pref[i-1][2];

        pref[i][--type]++;
    }
    while(q--){ 
        int a, b;
        cin >> a >> b;
        
        cout << pref[b][0] - pref[a-1][0] << " " << pref[b][1] - pref[a-1][1] << " " << pref[b][2] - pref[a-1][2] << '\n';

    }
}
