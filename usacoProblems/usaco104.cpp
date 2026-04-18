#include <bits/stdc++.h>

using namespace std;
int const N = 1e6;
int start[N], endd[N];
int main(){
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    for(int i =0;i<k;i++){
        int a, b;
        cin >> a >> b;
        start[a] += 1;
        endd[b+1] -=1;
    }
    int stacks[n];
    memset(stacks,0,sizeof(stacks));
    int t = 0;
    for(int i =0;i<n;i++){
        t += start[i] + endd[i];
        stacks[i]+=t;
    }
    sort(stacks, stacks+n);

    cout << stacks[n/2];
}
