#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    vector<pair<int,int>> cords;
    for(int i =0;i<n;i++){
        int x, y;
        cin >> x >> y;
        cords.push_back({x-x0,y-y0});
    }
    int ans = 0;
    for(int i =0;i<n;i++) if(cords[i].first == 0) {ans++; break;}
    for(int i =0;i<n;i++) if(cords[i].second == 0){ans++; break;}
    int pos1=0, pos2=0;
    for(int i =0;i<n;i++){
        if((cords[i].first < 0 && cords[i].second < 0) ||
           (cords[i].first > 0 && cords[i].second > 0)){
            if(abs(cords[i].first)-abs(cords[i].second) != 0 || !pos1) ans++;
            if(abs(cords[i].first)-abs(cords[i].second) == 0) pos1 = 1;

        }
        if((cords[i].first > 0 && cords[i].second < 0) || 
           (cords[i].first < 0 && cords[i].second > 0)){
            if(abs(cords[i].first)-abs(cords[i].second) != 0 || !pos2) ans++;
            if(abs(cords[i].first)-abs(cords[i].second) ==0)  pos2 = 1;
        }
    }
    cout << ans; 
}
