#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;

    cin >> n;

    int i = 1;
    int v = 0, move = 0;
    while(abs(v) <= n){
        int s = 2*i-1;
        if(!move){
            v-=s;
        }else{
            v+=s;
        }
//        cout << abs(v) << " ";
        if(abs(v) > n){
            break;
        }
        i++;
        move = (move == 0)? move=1:move=0;
    }
    if(!move){
        cout << "Sakurako" << '\n';
    }else{
        cout << "Kosuke" << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) solve();
}
