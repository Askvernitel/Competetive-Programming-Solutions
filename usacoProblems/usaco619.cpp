#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("balancing.out", "w", stdout);
    freopen("balancing.in", "r", stdin);
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i =0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);
    int ans = INT_MAX;
    for(int i =0;i<n;i++){
        int y = a[i].second + 1;
        int x = a[i].first + 1;
        int f_half=0, s_half=0, t_half=0, fr_half=0;
        for(int j =0;j<n;j++){
            if(a[j].first > x && a[j].second > y){
                f_half++;
            }
            if(a[j].first < x && a[j].second > y){
                s_half++;
            }
            if(a[j].first > x && a[j].second < y){ 
                t_half++;
            }
            if(a[j].first < x && a[j].second < y){
                fr_half++;

            }

        }
        ans = min(ans, max({f_half, s_half, t_half, fr_half}));

    }
    cout << ans;


}
