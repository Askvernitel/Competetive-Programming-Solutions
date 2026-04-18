#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        // Read the grid.
        vector<vector<ll>> grid(n, vector<ll>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        
        // Build a boolean grid to mark the path cells.
        vector<vector<bool>> isPath(n, vector<bool>(m, false));
        
        // Simulate the path. Use 0-indexed coordinates.
        vector<pair<int,int>> path;
        int r = 0, c = 0;
        path.push_back({r, c});
        isPath[r][c] = true;
        for (char ch : s){
            if(ch == 'D'){
                r++;
            } else { // 'R'
                c++;
            }
            path.push_back({r, c});
            isPath[r][c] = true;
        }
        int pathLen = path.size(); // Should be n+m-1

        // For the magical property we choose the common sum x = 0.
        // Compute the required contribution for each row and column:
        // For row i, let R[i] = - (sum of fixed cells in row i)
        vector<ll> R(n, 0);
        for (int i = 0; i < n; i++){
            ll sum = 0;
            for (int j = 0; j < m; j++){
                if(!isPath[i][j])
                    sum += grid[i][j];
            }
            R[i] = -sum;
        }
        // Similarly, for each column j.
        vector<ll> C(m, 0);
        for (int j = 0; j < m; j++){
            ll sum = 0;
            for (int i = 0; i < n; i++){
                if(!isPath[i][j])
                    sum += grid[i][j];
            }
            C[j] = -sum;
        }
        
        // Determine the last occurrence of a path cell in each row and column.
        vector<int> lastInRow(n, -1), lastInCol(m, -1);
        for (int i = 0; i < pathLen; i++){
            int rr = path[i].first;
            int cc = path[i].second;
            lastInRow[rr] = i;
            lastInCol[cc] = i;
        }
        
        // We will assign adjustments to the path cells.
        // rowContrib and colContrib track how much has been assigned so far in each row/column.
        vector<ll> rowContrib(n, 0), colContrib(m, 0);
        vector<ll> pathVal(pathLen, 0);
        
        // Process each cell in the path in order.
        for (int i = 0; i < pathLen; i++){
            int rr = path[i].first, cc = path[i].second;
            bool lastRow = (i == lastInRow[rr]);
            bool lastCol = (i == lastInCol[cc]);
            ll assignVal = 0;
            if(lastRow && lastCol){
                // For the last path cell in both its row and column,
                // the remaining required adjustment must be the same.
                ll target = R[rr] - rowContrib[rr];
                // It must match the column requirement.
                assert(target == C[cc] - colContrib[cc]);
                assignVal = target;
            } else if(lastRow){
                assignVal = R[rr] - rowContrib[rr];
            } else if(lastCol){
                assignVal = C[cc] - colContrib[cc];
            } else {
                assignVal = 0; // not fixing any row/column yet
            }
            pathVal[i] = assignVal;
            rowContrib[rr] += assignVal;
            colContrib[cc] += assignVal;
        }
        
        // Build the answer grid: for fixed cells output the original value,
        // and for path cells output the newly assigned altitude.
        vector<vector<ll>> ans = grid;
        for (int i = 0; i < pathLen; i++){
            int rr = path[i].first, cc = path[i].second;
            ans[rr][cc] = pathVal[i];
        }
        
        // Output the resulting grid.
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

