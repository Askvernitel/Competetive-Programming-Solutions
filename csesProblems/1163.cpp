#include <bits/stdc++.h>

using namespace std;

map<int,int> m;
int main(){
    int x, n;
    cin >> x >> n;
    set<int> difs;
    priority_queue<int> pq;
    difs.insert(x); difs.insert(0);
    m[x]++;
    for(int i =0;i<n;i++){
        int p;
        cin >> p;
        auto it = difs.insert(p).first;
        int a = *next(it) - *it, b = *it - *prev(it);
        m[*next(it)-*prev(it)]--;
        m[a]++;
        m[b]++;
        pq.push(a); pq.push(b); 
        while(!m[pq.top()]) pq.pop();
        cout << pq.top() << " ";
    }


}
