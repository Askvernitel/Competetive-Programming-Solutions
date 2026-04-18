#include <bits/stdc++.h>

using namespace std;
char grid[3][3];
string ans;
int dir[3]={0, 1, -1};
void rec(int r, int c, string str, set<pair<int,int>>& vis){ 
	if(r < 0 || r >= 3 || c < 0 || c >= 3 || vis.find({r,c}) != vis.end()){
		return;
	}
	if(str.size() == 3){ 
		ans = min(str, ans);
		return;
	}
	vis.insert({r,c});
	str+=grid[r][c];
	for(int i = 0;i<3;i++){
		for(int j =0;j<3;j++){
			if(i == j){
				rec(r+dir[i], c+dir[j], str, vis);
			}
			else{ 
				rec(r+dir[i], c+dir[j], str, vis);
				rec(r+dir[j], c+dir[i], str, vis);
			}
		}
	}
	str.pop_back();
	vis.erase({r,c});
}
void solve(){
	ans = "CCC";
	for(int i = 0;i<3;i++){
		for(int j =0;j<3;j++){
			cin >> grid[i][j];
		}
	}
	
	for(int i =0;i<3;i++){
		for(int j =0;j<3;j++){
			set<pair<int,int>> s;
			rec(i,j,"",s);
		}
	}
	cout << ans << '\n';

}
int main(){
	solve();
}
