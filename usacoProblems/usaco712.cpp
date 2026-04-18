#include <bits/stdc++.h>

using namespace std;

int const N = 52;
int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    char arr[N];
    for(int i =0;i<N;i++) cin >> arr[i];
    int cnt = 0;
    int vis[26];
    memset(vis,0,sizeof(vis));
    for(int i =0;i<N;i++){
        char ch = arr[i];
        int chs[26];
        memset(chs, 0, sizeof(chs));
        //cout << ch - 'A' << '\n';
        if(!vis[ch-'A']){
            vis[ch -'A'] = 1;
            for(int j =i+1;j<N;j++){
                if(arr[j]==ch){
                   break;
                }
                chs[arr[j]-'A']++;
            }
        }
        for(int j =0;j<26;j++){
            if(chs[j] == 1) cnt++;
        }
    }
    //cout << cnt;
    cout << cnt/2;
}   
