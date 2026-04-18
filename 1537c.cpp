#include <bits/stdc++.h>


using namespace std;

int n;
void solve(){ 
        cin >> n;
        vector<int> h(n);
        for(int i =0;i<n;i++){ 
                cin >> h[i];
        }


        sort(h.begin(), h.end());

        int minv = INT_MAX;
        pair<int,int> p = {-1,-1};
        for(int i =0;i<n-1;i++){
                int diff = h[i+1]-h[i];

                if(diff < minv){ 
                        p.first = i;
                        p.second = i+1;
                        minv = diff;
                }
        }
        cout << h[p.first] << " ";
        for(int i =p.first+2;i<n;i++){
                cout << h[i] << " ";
        }
        for(int i =0;i<p.second-1;i++){
                cout << h[i] << " ";
        }
        cout << h[p.second];
        cout << '\n';
}
int main(){ 
        int tc;
        cin >> tc;


        while(tc--) solve();
}
