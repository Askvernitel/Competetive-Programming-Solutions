#include <bits/stdc++.h>

using namespace std;
int W, H, w, h;
int dist(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4){ 
    int dist1 = min(x2, x4)-max(x1, x3);
    int dist2 = min(y2,y4)-max(y1,y3);
    if(dist1 <= 0 || dist2 <= 0) return 0;
    

    if(x2 > x4 && x1 < x3){ 
        if(x2 == w && x1== 0){ 
            dist1 = x2-x3;
        }
        else if(x2 == W && x1 == W-w){ 
            dist1 = x4-x1;
        }
    }
    if(y2 > y4 && y1 < y3){ 
        if(y2 == h && y1 == 0){ 
            dist2 = y2-y3;
        }else if(y2 == H && y1==H-h){ 
            dist2 = y4-y1;
        }
    }



    if(W-abs(abs(x4-x3)+abs(x2-x1)) < 0) dist1= INT_MAX;
    if(H-abs(abs(y4-y3)+abs(y2-y1))< 0) dist2= INT_MAX;
    
    return min(dist1,dist2);
}
void solve(){
    
    int x1, y1, x2,y2;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    double ans = INT_MAX;
    ans = min({dist(0,0,w,h,x1,y1,x2,y2),
    dist(0,H-h,w,H,x1,y1,x2,y2),
    dist(W-w,0,W,h,x1,y1,x2,y2),
    dist(W-w,H-h,W,H,x1,y1,x2,y2)});
    if(ans == INT_MAX) ans = -1;
    cout << ans << '\n';
}
int main(){
    cout << setprecision(8) << fixed;
    int tc;
    cin >> tc;

    while(tc--) solve();

}
