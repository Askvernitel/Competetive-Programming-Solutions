#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int grid[2][n];
	set<int> used;
	int m = 2*n;
	grid[0][0] =m ;
	used.insert(m);
	grid[1][n-1] = m-1;
	used.insert(m-1);
	int cur1 = 1, cur2 = 0;
	int mv = 1;
	int first = 1, second = 2;
	int hi = m-2, lo = m-3;
	while(cur1 < n && cur2 < n){ 
		if(mv){ 
			while(used.find(first) != used.end()) first++;
			used.insert(first);
			while(used.find(second) != used.end()) second++;
			used.insert(second);
			grid[0][cur1]=first;
			grid[1][cur2]=second;
		}else{
			while(used.find(hi) != used.end()) hi--;
			used.insert(hi);
			while(used.find(lo) != used.end()) lo--;
			used.insert(lo);
			grid[1][cur2]=hi;
			grid[0][cur1]=lo;
		}
		cur1++;
		cur2++;
		mv = !mv;
	}
	for(int i =0;i<2;i++){
		for(int j =0;j<n;j++){
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
