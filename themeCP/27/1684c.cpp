#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int grid[n][m], cgrid[n][m];
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	memcpy(cgrid, grid, sizeof(grid));
	
	for(int i=0;i<n;i++){
		sort(grid[i], grid[i]+m);
	}
	set<pair<int,int>> s;
	bool pos = 1;

	for(int i =0;i<n;i++){
		int amount =0;
		int idx1 = -1, idx2 = -1;
		for(int j=0;j<m;j++){
			if(grid[i][j] != cgrid[i][j]){
				amount++;
				if(idx1 == -1) idx1 =j;
				else idx2 = j;
			}
		}
		if(amount > 2){
			pos = 0;
			break;
		}
		if(idx1 == -1 && idx2 == -1) continue;
		s.insert({idx1, idx2});
	}	
	if(!pos){ 
		cout << -1 << '\n';
		return;
	}
	if(s.size() == 1){ 
		pair<int,int> p= *s.begin();
		if(p.first != -1 && p.second != -1){ 
			for(int i =0;i<n;i++){
				int amount =0;
				swap(cgrid[i][p.first], cgrid[i][p.second]);
				for(int j=0;j<m;j++){
					if(grid[i][j] != cgrid[i][j]){
						amount++;
					}
				}
				if(amount > 0){
					cout << -1 << '\n';
					return;
				}
			}
			cout << p.first+1 << " " << p.second+1 << '\n';
		}else{ 
			cout << 1 << " " << 1 << '\n';
		}
		return;
	}else if(s.size() == 0){ 
		cout << 1 << " " << 1 << '\n';
		return;
	}
	else pos = 0;
			
	if(!pos){ 
		cout << -1 << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
