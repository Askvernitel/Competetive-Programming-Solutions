#include <bits/stdc++.h>

using namespace std;
void print(vector<int> vec){ 
    for(int i =0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main(){
    freopen("swap.out", "w", stdout);
    freopen("swap.in", "r", stdin);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    set<vector<int>> s;
    for(int i =0;i<n;i++){
        a[i]=i+1;
    }
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    vector<vector<int>> ns;
    while(s.find(a) == s.end()){
        ns.push_back(a);
        s.insert(a);
        reverse(a.begin()+a1-1, a.begin()+a2);
        reverse(a.begin()+b1-1, a.begin()+b2);
        //print(a);
    }
    int th = k%(int)(s.size());
    int p = 0;
    for(vector<int> v:ns){
        if(p == th){ 
            for(int x:v){
                cout << x << '\n';
            }
            break;
        }
        p++; 
    }

    
}
