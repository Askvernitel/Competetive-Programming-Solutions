#include <bits/stdc++.h>

using namespace std;

vector<int> getRange(vector<int> p){
    int n = p.size();
    sort(p.begin(), p.end());
    vector<int> result;

    for(int i =0;i<n;i++){
        if(i <= n/4) continue;
        if(i >= n - n/4) continue;
        result.push_back(p[i]+1);
    }
    return result;
}

int main(){
freopen("balancing.in", "r", stdin);
freopen("balancing.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    
    vector<int> gb = getRange(b);
    vector<int> ga = getRange(a);

    int ans = INT_MAX;


    for(int x: ga){
        for(int y : gb){
            int f_half = 0, s_half=0, t_half =0, fr_half=0;

            for(int i=0;i<n;i++){
                if(a[i] > x && b[i] > y){
                    f_half++;
                }
                else if(a[i] > x && b[i] < y){
                    s_half++;
                }
                else if(a[i] < x && b[i] > y){
                    t_half++;
                }
                else{
                    fr_half++;
                }
            }
//            cout << f_half << " " << s_half << " " << t_half << " " << fr_half << '\n';
            int mx = max({f_half, s_half, t_half, fr_half});
            ans = min(ans, mx);
        }
  //      cout << '\n';
    }
    cout << ans <<'\n';
    
}
