#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<char> stack;
	int ans = 0;
	for(int i =0;i<n;i++){
		if(s[i] == '0'){
			ans += (i+1);
		}
	}
	for(int i =0;i<n;i++){
		char p = s[i];
		if(stack.empty()){
			stack.push_back(p);
			continue;
		}
		if(stack.back() == '0' && p == '1'){
			stack.pop_back();
		}else{
			stack.push_back(p);
		}
	}
	int cnt =0;
	for(int i =0;i<stack.size();i++){
		if(stack[i] == '1') cnt++;
	}
	cnt = (cnt+1)/2	;
	for(int i =0;i<n;i++){
		if(cnt == 0) break;
		if(s[i] == '1'){
			ans += (i+1);
			cnt--;
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
