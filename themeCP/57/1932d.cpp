#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
void solve(){
	int n;
	cin >> n;
	char ch;
	cin >> ch;
	string s[2*n];
	for(int i =0;i<2*n;i++){
		cin >> s[i];
	}

	vector<string> tr,nr;
	for(int i = 0;i<2*n;i++){
		if(s[i][1] == ch) tr.push_back(s[i]);
		else nr.push_back(s[i]);
	}
	int m = nr.size(), p = tr.size();
	sort(tr.begin(), tr.end());
	vector<pair<string, string>> ans;
	int cur=0;
	for(int i = 0;i<m;i++){
		if(nr[i] == "#") continue;
		bool found = 0;
		for(int j =i+1;j<m;j++){
			if(nr[j] == "#") continue;
			if(nr[i][1] == nr[j][1]){
				if(nr[j][0] > nr[i][0]) ans.push_back({nr[i], nr[j]});
				else ans.push_back({nr[j], nr[i]});
				nr[i]="#";
				nr[j]="#";
				found=1;
				break;
			}
		}
		if(!found && cur == p){ 
			cout << "IMPOSSIBLE\n";
			return;
		}else if(!found){
			ans.push_back({nr[i], tr[cur]});
			cur++;
		}
	}
	if(((p-cur)%2)){ 
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(int i =cur;i<p-1;i+=2){
		ans.push_back({tr[i], tr[i+1]});
	}
	int z = ans.size();
	for(int i =0;i<z;i++){
		cout << ans[i].F << " " << ans[i].S << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
