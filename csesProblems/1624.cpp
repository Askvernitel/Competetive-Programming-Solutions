#include <bits/stdc++.h>

using namespace std;

int const N = 8, M = 8;
char arr[N][M];
int p[N][M];
int ans = 0;
void solve(int r){
    if(r == N){
        ans++;
        return;
    }
    for(int i = 0;i<M;i++){
        if(arr[r][i] == '*') continue;
        int k = 0, t = 1;
        for(int j = 0; j<r;j++) if(p[j][i]) t = 0;
        for(int j =i-r;j<i;j++){
            if(j >= 0 && p[k][j]) t = 0;
            k++;
        }
        k=0;
        for(int j =i+r;j>i;j--){
            if(j < M && p[k][j]) t = 0;
            k++;
        }
        if(t){
            p[r][i] = 1;
            solve(r+1);
            p[r][i] = 0;
        }
       
    }

}

int main(){

    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            cin >> arr[i][j]; 
        }
    }
    solve(0);

    cout << ans;
}   
