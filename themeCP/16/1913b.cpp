#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;

	int n = s.size();
	int cnt1=0, cnt0=0;
	for(int i =0;i<n;i++){
		if(s[i] == '1') cnt1++;
		else cnt0++;
	}
	int idx = n;
	for(int i =0;i<n;i++){
		
		if(s[i] == '1') cnt0--;
		else cnt1--;
		if(cnt0 < 0 || cnt1 < 0){
			idx=i;
			break;
		}
	}

	cout << n-idx << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
