#include <bits/stdc++.h>

using namespace std;

int dfs(int cur, map<int, vector<int>>& tree, int q, int b, int n, int step){
    if(tree[cur].size()==0) return b;
    int mark[2] = {0,0};
    int val;
    //cout << n/2 << endl;
    if(q > n/2){
        val = dfs(tree[cur][1], tree, q, b, n/2, step + 1);
        mark[1] = 1;
    }else{ 
        val = dfs(tree[cur][0], tree, q, b, n/2, step + 1);
        mark[0] = 1;
    } 
    cout << val << " ";
    if(mark[1]){
        tree[cur][1] = val;
    }else{
        tree[cur][0] = val;
    }
    int k = (step%2)?(tree[cur][1] | tree[cur][0]):(tree[cur][1] ^ tree[cur][0]);
    tree[k] = tree[cur];
    if(k != cur) tree[cur] = {};
    return k;
}

int n, m;
int main(){
    cin >> n >> m;

    int t = (1 << n);
    vector<int> a;
    for(int i =0;i<t;i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    map<int,vector<int>> tree;
    vector<int> p;
    int c = 0;
    while(a.size() != 1){
        for(int i =0;i<a.size();i+=2){
            if(c%2) p.push_back((a[i] ^ a[i+1])); 
            else p.push_back((a[i] | a[i+1]));
        }
        int s=0;
        for(int i =0;i<p.size();i++){
            tree[p[i]].push_back(a[s]);
            s++;
            tree[p[i]].push_back(a[s]);
            s++;
        }
        a=p;
        p.clear();
        c++;
    }
    int root = a[0];
    while(m--){
        int p, b;

        cin >> p >> b;
       // cout << root << endl;
        vector<int> prevroot = tree[root];
        root = dfs(root, tree, p, b , t, 0);
        tree[root] = prevroot;
        cout << root << endl;


    }

}
