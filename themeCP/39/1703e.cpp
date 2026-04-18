#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> dir[n][n];
	char grid[n][n];
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			cin >> grid[i][j];
			if(grid[i][j] == '1'){ 
				dir[i][j].push_back(i);
				dir[i][j].push_back(n-j-1);
			}
		}
	}
	int ans =0;	
	for(int i = 0;i <n;i++){
		for(int j =0;j<n;j++){
			if(grid[i][j] != '1') continue;
			int cnt1 = 0;
			int cnt0 = 1;
			int r= n-i-1;
			int c= n-j-1;
			if(grid[r][c] == '0'){
				grid[r][c]='1';
				cnt1++;
			}else cnt0++;
			int r1 = j;
			int c1 = n-i-1;
			if(grid[r1][c1] == '0'){
				grid[r1][c1]='1';
				cnt1++;
			}else cnt0++;
			int r2=n-r1-1;
			int c2 = i;
			if(grid[r2][c2] == '0'){
				grid[r2][c2]='1';
				cnt1++;
			}else cnt0++;
			if(cnt1 > cnt0){ 
				grid[r2][c2]='0';
				grid[r1][c1]='0';
				grid[r][c]='0';
				grid[i][j]='0';
				ans += cnt0;
			}else ans += cnt1;
		}
	}
	cout << ans << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
