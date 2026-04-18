#include <bits/stdc++.h>
using namespace std;

int times[1001];
int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> shifts[n];
    for(int i =0;i<n;i++){
        int start, end;
        cin >> start >> end;
        
        for(int i = start;i<end;i++){
            times[i]++;
        }
        shifts[i] = {start, end};
    }
    int cnt = 0;
    for(int i =0;i<1001;i++) if(times[i] >0) cnt++;

    int ans = 0;
    for(int i=0;i<n;i++){
        int k = 0;
        for(int j = shifts[i].first;j<shifts[i].second;j++){
            if(times[j] == 1) k++;
        }
        ans = max(ans, cnt - k);
    }
    cout << ans;

}
