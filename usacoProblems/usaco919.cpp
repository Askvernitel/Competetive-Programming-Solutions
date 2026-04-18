#include <bits/stdc++.h>

using namespace std;
int fence[1001][1001];
void mark(int x1, int y1, int x2, int y2){
    
    for(int i =y1;i<y2;i++){
        fence[i][x1] = 1;
        fence[i][x2] = -1;
    }
}
int main(){
//    freopen("paintbarn.in", "r", stdin);
 //   freopen("paintbarn.out", "w",stdout);
    int k, n;
    cin >> n >> k;
    


    for(int i =0;i<n;i++){
        int x1,y1,x2,y2;

        cin >> x1 >> y1 >> x2 >> y2;
        
        mark(x1, y1, x2, y2);
    }

    for(int i= 0;i<1001;i++){
        for(int j = 1;j<1001;j++){
            fence[i][j] += fence[i][j-1];
        }
    }
    int ans = 0;
    for(int i =0;i<1001;i++){
        for(int j = 0;j<1001;j++){
            if(fence[i][j] == k) ans++;
        }
    }
/*    for(int i =0;i<10;i++){
        for(int j =0;j<10;j++){
            cout << fence[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << ans;

}
