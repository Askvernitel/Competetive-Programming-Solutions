#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> cords[n];
    for(int i =0;i<n;i++) cin >> cords[i].first >> cords[i].second; 

    int ans = 0;
    for(int i =0;i<n;i++){
        for(int j=i+1; j<n;j++){
            for(int k = j+1;k<n;k++){
                pair<int,int> c1 = cords[i], c2 = cords[j], c3 = cords[k];

                if(c1.first == c2.first && (c3.second == c2.second || c3.second == c1.second)){
                    ans = max(ans,abs(c1.second-c2.second) * abs(c3.first - c2.first));
                }
                if(c1.first == c3.first && (c2.second == c3.second || c2.second == c1.second)){
                    ans = max(ans,abs(c1.second -c3.second) * abs(c2.first - c3.first));
                }
                if(c2.first == c3.first && (c2.second == c1.second || c3.second == c1.second)){
                    ans = max(ans,abs(c2.second - c3.second) * abs(c2.first - c1.first));
                }
            }
        }

    }

    cout << ans;
}
