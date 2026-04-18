#include <bits/stdc++.h>

using namespace std;
bool exists(set<int>& s, int val){
	return s.find(val) != s.end();
}
void solve(){
	int n,m;
	cin >> n >> m;
	char grid[n][m]; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	set<int> br, bc;
	set<int> wr, wc;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(grid[i][j] == 'W'){
				wr.insert(i);
				wc.insert(j);
			}else{
				br.insert(i);
				bc.insert(j);
			}
		}
	}
	if((grid[0][0] == grid[n-1][m-1]) || (grid[0][m-1] == grid[n-1][0])){
		cout << "YES\n";
		return;
	}

	if(exists(br,0) && exists(br, n-1) && exists(bc, m-1) && exists(bc,0)){
		cout << "YES\n";
		return;
	}
	if(exists(wr,0) && exists(wr, n-1) && exists(wc, m-1) && exists(wc,0)){
		cout << "YES\n";
		return;
	}
	if(((int)br.size()==n && (int)bc.size() ==m) || ((int)wr.size()==n && (int)wc.size()==m)){
		cout << "YES\n";
		return;
	}
	cout <<"NO\n";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
