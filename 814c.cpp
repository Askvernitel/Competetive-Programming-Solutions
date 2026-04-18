#include <bits/stdc++.h>

using namespace std;
map<char, vector<int>> m1;
string s;
int cnt = 0;
int good_cnt = 0;
vector<int> a;
void remove(int idx){ 
    if(idx > 0){ 
        cnt -=(a[idx]-a[idx-1]-1);
    }else{
        cnt -=a[idx];
    }
}
void add(int idx){
    if(idx > 0){
        cnt += (a[idx]-a[idx-1]-1);
    }else{ 
        cnt += a[idx];
    }
}

bool good(){ 
    return cnt <= good_cnt;
}
int calc(int m, char c){ 
    a = m1[c]; cnt = 0;
    int n = a.size();
    cnt =0;good_cnt=m;
    a.push_back((int)s.size());
    int l = 0, ans = 0;
    for(int r = 0;r<=n;r++){
        add(r);
        while(!good()){
            remove(l++);
        }
        int f=(l > 0)? a[l-1]:0;
        int t = (a[r] ==s.size())?0:1;
        ans = max(ans, min((int)s.size(),a[r]-f+t+(good_cnt-cnt)));
    }
    return ans;
}
int main(){
    int n, q;
    cin >> n;
    cin >> s >> q;

    for(int i = 0;i<n;i++) {
        m1[s[i]].push_back(i);
    }
    while(q--){
        char c;
        int m;
        cin >> m >> c;

        cout << max(calc(m, c),m) << '\n';
        
    }
}
