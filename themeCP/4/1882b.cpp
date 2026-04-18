#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	map<int,int> a[n];
	map<int,vector<int>> m;
	map<int,int> ss;
	for(int i =0;i<n;i++){
		int k;
		cin >> k;

		for(int j =0;j<k;j++){
			int num; cin >> num;
			a[i][num]++;
			ss[num]++;
		}
		for(auto &[x,_]:a[i]){
			m[x].push_back(i);
		}
	}

	int ans =0;
	for(auto &[x, vec]:m){ 
		map<int,int> cc = ss;
		for(int v:vec){
			for(auto &[c,d]:a[v]){
				cc[c] -= d;
			}
		}
		int cur = 0;
		for(auto &[c,d]:cc){
			if(d > 0) cur++;
		}
		ans = max(ans,cur);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
