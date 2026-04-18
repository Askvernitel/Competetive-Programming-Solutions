#include <bits/stdc++.h>

using namespace std;
bool check(int x, int y, int x1, int y1, int x2, int y2){
    
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2, x3,y3, x4,y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int cnt = 0;
    if(check(x1, y1, x3, y3, x4, y4)) cnt++;
    if(check(x1, y2, x3, y3, x4, y4)) cnt++;
    if(check(x2, y1, x3, y3, x4, y4)) cnt++;
    if(check(x2, y2, x3, y3, x4, y4)) cnt++;

    if(cnt<2){
        cout << (x2-x1) * (y2-y1);
    }else if(cnt == 4){
        cout << 0;
    }else{
        int interx = min(x2,x4)-max(x1,x3);
        int intery = min(y2,y4)-max(y1,y3);

        cout << ((x2-x1) * (y2-y1)) - (interx*intery);
    }
}
