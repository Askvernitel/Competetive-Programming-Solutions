#include <bits/stdc++.h>

#define OUT(a) cout << a << '\n'
using namespace std;
void solve(){ 
        int n;
        cin >> n;


        int b[n];
        for(int i =0;i<n;i++){
                cin >> b[i];
        }

        map<int,vector<int>> m;

        for(int i =0;i<n;i++){
                m[b[i]].push_back(i);
        }

        int a[n];
        for(auto const [k, v] : m){
                if(((int)v.size())%k != 0){ 
                        OUT(-1);
                        return;
                }
        }
        int last_value = 1; 
        for(auto const [k, v] : m){ 
                int cnt = 0; 
                for(int e : v){ 
                        cnt++;
                        a[e] = last_value;
                        if(cnt%k == 0){ 
                                last_value++;
                        }
                }
        }

        for(int i =0;i<n;i++){
                cout << a[i] << " ";
        }

        cout << '\n';
}
int main(){ 
        int tc;

        cin >> tc;

        while(tc--) solve();
}
