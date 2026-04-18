#include <bits/stdc++.h>
using namespace std;
int calc(int x1, int y1, int x2, int y2){
    return abs(y2-y1) * abs(x2-x1);
}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;


    int inter1y = max(min(y4,y6) - max(y3,y5), 0);
    int inter1x = max(min(x6,x4) - max(x5,x3), 0);
    int inter2y = max(min(y6,y2) - max(y5,y1), 0);
    int inter2x = max(min(x6,x2) - max(x5,x1), 0);
    
    int area1 = calc(x1,y1,x2,y2); 
    int area2 = calc(x3,y3,x4,y4);
    int inter1 = inter1y*inter1x;
    int inter2 = inter2y*inter2x;

    cout << area1 + area2 - inter1 - inter2;
}
