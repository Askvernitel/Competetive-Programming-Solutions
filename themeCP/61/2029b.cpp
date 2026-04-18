#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	string s, r;
	cin >> s >> r;
	int m =r.size();
	int cnt1=0, cnt0=0;
	for(int i = 0;i<n;i++){
		if(s[i] == '1') cnt1++;
		else cnt0++;
	}

	for(int i = 0;i<m;i++){

		if(cnt1 ==0 || cnt0 == 0){ 
			cout << "NO\n";
			return;
		}
		if(r[i] == '1'){ 
			cnt0--;
		}else if(r[i] == '0'){
			cnt1--;
		}
	}
	if(cnt1 < 0 || cnt0 < 0){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
