#include <bits/stdc++.h>

using namespace std;

int canv[15][15];

int n;
bool exists(int color){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(canv[i][j] == color){
                return true;
            }
        }
    }
    return false;
}
bool check(int col1, int col2){
    int top = n, bottom = 0,left=n, right=0; 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(canv[i][j] == col2){
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

    for(int i =top;i<=bottom;i++){
        for(int j = left; j<=right;j++){
            if(canv[i][j] == col1) return false;
        }
    }
    return true;
}
int main(){
freopen("art.in", "r", stdin);
freopen("art.out", "w", stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            char ch;
            cin >> ch;
            canv[i][j] = ch-'0';
        }
    }
    int ans = 0;
    for(int i = 1;i<10;i++){
        int pos = 0;
        if(exists(i)){ 
            pos = 1;
            for(int j =1;j<10;j++){
                if(i != j && exists(j)){
                    if(!check(i,j)){
                        pos = 0;
                        break;
                    }
                }
            }
        }
        if(pos) ans++;

    }
    cout << ans << '\n';




}
