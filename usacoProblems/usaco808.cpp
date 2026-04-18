#include <bits/stdc++.h>

using namespace std;
int diff(set<int>& m, set<int>& s){ 
    int res = 0;
    for(int x:s){ 
        if(m.find(x) == m.end()) res++;
    }
    return res;
}
void exp(set<int>& e, set<int>& s){ 
    for(int x:s){ 
        e.insert(x);
    }
}
int main(){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    sort(a, a+n);
    set<int> arr[n];
    for(int i =0;i<n;i++){
        int cur = i;
        set<int> vis;
        while(vis.find(cur) == vis.end()){ 
            vis.insert(cur);
            if(cur == 0) cur++;
            else if(cur+1 < n && a[cur+1]-a[cur] < a[cur] - a[cur-1]) cur++; 
            else cur--;
        }
        arr[i] = vis;
    }
    int ans =0;
    set<int> t;
    for(int i =0;i<n;i++){
        if(t.size() == n) break;
        int d = 0;
        set<int> best; 
        for(int j =0;j<n;j++){
            int p = diff(t,arr[j]);
            if(p> d){ 
                d = p;
                best = arr[j];
            }
        }
        exp(t, best);
        ans++;
    }
    cout << ans;
}
