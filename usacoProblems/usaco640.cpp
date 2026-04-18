#include <bits/stdc++.h>

using namespace std;

char grid[8][8];
char d[8][8];
int n, k;


vector<vector<pair<int,int>>> match(vector<pair<int,int>>& m, vector<pair<int,int>>& s){ 
    vector<vector<pair<int,int>>> ans;
    int mark[int(m.size())];
    for(int x = -9;x<=9;x++){
        for(int y=-9;y<=9;y++){ 
            vector<pair<int,int>> res;
            memset(mark, 0, sizeof(mark));
            for(int i =0;i<s.size();i++){

                for(int j =0;j<m.size();j++){

                    if(!mark[j] && s[i].first+x == m[j].first && s[i].second+y==m[j].second){
                        mark[j] = 1;
                        break;
                    }
                }
            }
            for(int i=0;i<m.size();i++){
                if(!mark[i]){ 
                    res.push_back(m[i]);
 //                   cout << res[i].first << "," << res[i].second << "   ";
                }
            }
//            cout << res.size() << " " << m.size() << " " << s.size() << '\n';
            if(res.size() == m.size()-s.size()) ans.push_back(res);

        }
    }

    return ans;
}
int main(){
    freopen("bcs.out", "w", stdout);
    freopen("bcs.in", "r", stdin);
    cin >> n >> k;
    
    vector<pair<int,int>> coords;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> grid[i][j];
            if(grid[i][j] == '#') coords.push_back({i,j});
        }
    }
    

    vector<vector<pair<int,int>>> v;
    for(int i =0;i<k;i++){
        vector<pair<int,int>> t;
        for(int j = 0;j<n;j++){
            for(int u= 0;u<n;u++){
                char ch;
                cin >> ch;
                if(ch == '#'){
                    t.push_back({j, u});
                }
            }
        }
        v.push_back(t);
    }

    for(int i =0;i<k;i++){
        vector<vector<pair<int,int>>> matches;
        matches = match(coords,v[i]);
        for(int j =0;j<k;j++){
            if(j == i) continue;
            for(int u =0;u<matches.size();u++){
                vector<vector<pair<int,int>>> cur_match = match(matches[u], v[j]);
                for(int z =0;z<cur_match.size();z++){
                    if(cur_match[z].size() == 0){
                        cout << i+1 << " " << j+1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    

}
