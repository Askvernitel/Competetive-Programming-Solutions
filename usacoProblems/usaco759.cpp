#include <bits/stdc++.h>

using namespace std;
int area[2003][2003];
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    for(int k=0;k<3;k++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = y1+1000; i < y2+1000;i++){
            for(int j =x1+1000;j<x2+1000;j++){
                if(k < 2) area[i][j] = 1;
                else area[i][j] = 2;
            }
        }
    }
    int ans = 0;
    for(int i =0;i<2003;i++){
        for(int j =0;j<2003;j++){
            if(area[i][j] == 1) ans++;
        }
    }
    cout << ans;
}   
