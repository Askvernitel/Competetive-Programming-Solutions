#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[500001][2];
int n, d;
int tot = 0;
int l = 0,r =0;
int cnt[2];

void add(int type){ 
    cnt[type]++;
    if(type==0){ 
        tot += cnt[1];
    }
}

bool good(){
    if(r-l+1<= 1) return true;
//    cout << a[r][0] - a[l][0] << '\n';
    if(a[r][0] - a[l][0] > d){ 
        return false;
    }

    return true;
}

void remove(int type){
    cnt[type]--;
    if(type == 1){ 
        tot-=cnt[0];
    }
}
    
signed main(){
    ios_base::sync_with_stdio(false);
    
    cin >> n >> d;

    for(int i = 0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    int ans = 0;
    for(r = 0;r<n;r++){
        add(a[r][1]);
        while(!good()){ 
            remove(a[l++][1]);
        }
        if(a[r][1] == 1){ 
            ans+=tot;
        }
    }

    cout << ans;


}
